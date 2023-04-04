from collections import defaultdict
from getpass import getuser
from fastapi import FastAPI, WebSocket
import uvicorn
import time, threading, queue
import datetime as dt
import json
app = FastAPI(title='API')




class connectionUser:
    def __init__(self, id, pose):
        self.id = id
    id: str

connections = []


def getUser (id):
    return next(x for x in connections if x.id == id)


@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()

    while True:
        try:
            data = await websocket.receive_json()
            if(data["type"] == "updateState"):
                print("lol")
        except Exception as e:
            print("error: ", e)
            break

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=5000)