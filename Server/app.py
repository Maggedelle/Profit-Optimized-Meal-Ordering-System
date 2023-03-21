from flask import Flask, jsonify
from flask import request
from flask_sock import Sock

app = Flask(__name__)
sock = Sock(app)

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

@sock.route('/socket')
def socket(ws):
    while True:
        text = ws.receive()
        print(text)

if __name__ == '__main__':
    app.run('0.0.0.0', port=5000)