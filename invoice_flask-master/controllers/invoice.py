from flask import *

invoice = Blueprint('invoice', __name__, template_folder='views')

@invoice.route("/invoice", methods=['POST', 'GET'])
def invoice_route():

	products = {"Apple":1.50,"Orange":2.00,"Strawberry":3.00,"Kiwi":0.75,"Watermelon":6.00,"Grape":0.45,"Lemon":0.90,"Cherry":4.35,"Blueberry":0.75,"Kumquat":1.10,"Pineapple":2.50,"Mango":2.25,"Peach":3.25,"Starfruit":5.00,"Blackberry":1.00}

	return render_template("invoice.html",products=products)
