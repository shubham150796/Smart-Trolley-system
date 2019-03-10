from flask import Flask, render_template
from flask.ext.mysqldb import MySQL
import controllers

app = Flask(__name__, template_folder="templates", static_folder="static")

app.register_blueprint(controllers.invoice)

if __name__ == "__main__":
  app.run()