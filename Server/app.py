from flask import Flask, jsonify
from flask import request
app = Flask(__name__)


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
    
app.run('0.0.0.0', port=5000)