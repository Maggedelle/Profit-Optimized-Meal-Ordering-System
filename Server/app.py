from fastapi import FastAPI, WebSocket, WebSocketDisconnect
import uvicorn
import datetime as dt
import json
import threading
import random
import asyncio
app = FastAPI(title='API')




class ConnectionUser:
    def __init__(self, id, online, socket):
        self.id = id
        self.online = online
        self.socket = socket
    id: str
    online: bool
    socket:WebSocket


class ConnectionManager:
    def __init__(self):
        self.active_connections: list[WebSocket] = []

    async def connect(self, websocket: WebSocket):
        await websocket.accept()
        self.active_connections.append(websocket)

    def disconnect(self, websocket: WebSocket):
        self.active_connections.remove(websocket)

    async def send_personal_message(self, message, websocket: WebSocket):
        await websocket.send_json(message)

    async def broadcast(self, message: str):
        for connection in self.active_connections:
            await connection.send_text(message)


manager = ConnectionManager()
 

connections:ConnectionUser = []

def getUser (id) -> ConnectionUser:
    try:
        return next(x for x in connections if x.id == id)
    except:
        return None


async def sendOrderToUser (userId):
    user = getUser(userId)

    if(user):
        objectToEmit = {
            "type": "user_recived_order",
            "order": "someOrder"
        }
        await manager.send_personal_message(json.dumps(objectToEmit), user.socket)
        print("sent order to user!")
    else:
        raise Exception("Can't send order because user doesn't exist")


def sendOrderToRandomUser ():
    print("trying to send order to random user...")
    if(len(connections) > 0):
        randomUser = random.choice(connections)

        loop = asyncio.new_event_loop()
        asyncio.set_event_loop(loop)
        loop.run_until_complete(sendOrderToUser(randomUser.id))
        loop.close()
    startOrderSimulationThread()



def startOrderSimulationThread ():
    threading.Timer(25.0, sendOrderToRandomUser).start()

@app.websocket("/ws/{client_id}")
async def websocket_endpoint(websocket: WebSocket, client_id: str):
    await manager.connect(websocket)
    try:
        while True:
            data = await websocket.receive_json()
            if(data["type"] == "updateState"):
                user = getUser(data["id"])
                if not user:
                    connections.append(ConnectionUser(data["id"], data["online"], websocket))
                    print(data["id"] + " connceted")
                else:
                    user.online = data["online"]
                    print(data["id"] + " changed it's online-status to " + str(data["online"]))
    except WebSocketDisconnect:
        manager.disconnect(websocket)

if __name__ == "__main__":
    startOrderSimulationThread()
    uvicorn.run(app, host="0.0.0.0", port=5000)