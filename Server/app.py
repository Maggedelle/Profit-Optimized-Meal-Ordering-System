from flask import Flask

app = Flask(__name__)

@app.route("/")
def hello_magnus():
    return "<p> Hello, Magnus :)!</p>"
