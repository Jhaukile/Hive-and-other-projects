import json
from datetime import datetime
from flask import Flask, request

app = Flask(__name__)
@app.route('/', methods =['GET', 'POST'])

def delicalcs():

    data_json = request.get_data()
    data_json = json.loads(data_json)
    cart_value = data_json['cart_value']
    delivery_distance = data_json['delivery_distance']
    number_of_items = data_json['number_of_items']
    time = data_json['time']


    #if cartvalue is less than 10€, add surcharge of the difference
    if (cart_value < 1000):
        surcharge = 1000 - cart_value

    # A delivery fee for the first 1000 meters (=1km) is 2€. 
    # If the delivery distance is longer than that, 
    # 1€ is added for every additional 500 meters that the courier needs 
    # to travel before reaching the destination. 
    # Even if the distance would be shorter than 500 meters,
    #  the minimum fee is always 1€. 

    tripfee = 200
    if (delivery_distance > 1000):
        tripfee =(delivery_distance // 500) * 100
        if (delivery_distance % 500 > 0):
            tripfee += 100

    # If the number of items is five or more,
    #  an additional 50 cent surcharge is added for
    #  each item above and including the fifth item.
    #  An extra "bulk" fee applies for more than 12 items of 1,20€
    bulkfee = 0
    if (number_of_items > 4):
        bulkfee = (number_of_items - 4) * 50
    if (number_of_items > 12):
        bulkfee += 120

    deliveryfee = surcharge + tripfee + bulkfee

    #The delivery is free (0€) when the cart value is equal or more than 100€.
    if (cart_value > 9999):
        deliveryfee = 0

    #During the Friday rush (3 - 7 PM UTC),
    #  the delivery fee (the total fee including possible surcharges)
    #  will be multiplied by 1.2x. However, 
    # the fee still cannot be more than the max (15€).

    rush = False
    datetimeobj = datetime.fromisoformat(time)

    #Checks if friday and time between 15:00 and 19:00
    if(datetimeobj.weekday() == 4):
        if (datetimeobj.hour >= 15 and datetimeobj.hour < 19):
            rush = True

    if (rush):
        deliveryfee *= 1.2

    #The delivery fee can never be more than 15€, including possible surcharges.
    if (deliveryfee > 1500):
        deliveryfee = 1500

    deli = {
        "delivery-fee": int(deliveryfee)
    }
    return json.dumps(deli)

app.run()  # run our Flask app
