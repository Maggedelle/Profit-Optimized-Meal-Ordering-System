from fastapi import FastAPI, WebSocket
import uvicorn
import datetime as dt
import json
app = FastAPI(title='API')




class connectionUser:
    def __init__(self, id, online, socket):
        self.id = id
        self.online = online
        self.socket = socket
    id: str
    online: bool
    socket:WebSocket

connections:connectionUser = []


def getUser (id) -> connectionUser:
    try:
        return next(x for x in connections if x.id == id)
    except:
        return None


def sendOrderToUser (userId):
    user = getUser(userId)

    if(user):
        objectToEmit = {
            "type": "user_recived_order",
            "order": "someOrder"
        }
        user.socket.send_json(json.dumps(objectToEmit))
    else:
        raise Exception("Can't send order because user doesn't exist")


@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()

    while True:
        try:
            data = await websocket.receive_json()
            if(data["type"] == "updateState"):
                user = getUser(data["id"])
                if not user:
                    connections.append(connectionUser(data["id"], data["online"], websocket))
                    print(data["id"] + " connceted")
                else:
                    user.online = data["online"]
                    print(data["id"] + " changed it's online-status to " + str(data["online"]))
                   
        except Exception as e:
            print("error: ", e)
            break

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=5000)