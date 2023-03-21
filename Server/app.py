from flask import Flask, jsonify
from flask import request
from flask_socketio import SocketIO

async_mode = None
app = Flask(__name__)
socket_ = SocketIO(app, async_mode=async_mode)

onlineUsers = []


@app.route("/")
def hello_magnus():
    return "<p> Hello, Magnus :)!</p>"


@app.route("/worker/state", methods = ['POST'])
def updateState():
    data = request.get_json()
    if(data["online"] == True):
        onlineUsers.append(data["id"])
    else:
        onlineUsers.remove(data["id"])
    
    print(onlineUsers)
    return data

if __name__ == '__main__':
    socket_.run(app, debug=True)   
    app.run('0.0.0.0', port=5000)