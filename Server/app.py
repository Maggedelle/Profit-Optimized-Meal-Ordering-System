from flask import Flask
from flask import request
app = Flask(__name__)


@app.route("/")
def hello_magnus():
    return "<p> Hello, Magnus :)!</p>"


@app.route("/worker/state", methods = ['POST'])
def updateState():
    data = request.data
    print(data)
    return data
    
app.run('0.0.0.0', port=5000)