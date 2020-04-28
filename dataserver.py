import json
from flask import Flask, request, redirect, session, url_for, Response, json
from flask.json import jsonify
from pymongo import MongoClient
from pprint import pprint
import math
import time
from flask_cors import CORS
from bson import ObjectId
import bson.json_util as bs 

class JSONEncoder(json.JSONEncoder):
    def default(self, o):
        if isinstance(o, ObjectId):
            return str(o)
        return json.JSONEncoder.default(self, o)


with open('credentials.json', 'r') as f:
    creds = json.load(f)

mongostr = creds["mongostr"]
client = MongoClient(mongostr)

db = client["freshAir"]

##test location
lat1 = 27.943363
lon1 = -82.452635



app = Flask(__name__)
CORS(app)

def getAllReadings():
    col = db.readings
    data = col.find()
    
    # user = col.find_one({"areaname": str(aname)})

    return data


def haversine(coord1, coord2):
    R = 6372800  # Earth radius in meters
    lat1, lon1 = coord1
    lat2, lon2 = coord2
    
    phi1, phi2 = math.radians(lat1), math.radians(lat2) 
    dphi       = math.radians(lat2 - lat1)
    dlambda    = math.radians(lon2 - lon1)
    
    a = math.sin(dphi/2)**2 + \
        math.cos(phi1)*math.cos(phi2)*math.sin(dlambda/2)**2
    
    return 2*R*math.atan2(math.sqrt(a), math.sqrt(1 - a))


@app.route("/dummy", methods=['GET', 'POST'])
def dummy():

    ##res = request.json
    
    print ("now inside dummy call")

    js = "<html> <body>OK THIS WoRKS</body></html>"

    resp = Response(js, status=200, mimetype='text/html')
    ##resp.headers['Link'] = 'http://google.com'

    return resp



@app.route("/insertReading", methods=['GET', 'POST'])
def insertReading():

    # print(request)

    res = request.get_json()
    print (res)

    if res is not None:


        payload = {}
        payload["lat"] = str(lat1)
        payload["lon"] = str(lon1)
        ts = int(time.time())
        payload["deviceid"] = "001"
        payload["timestamp"] = str(ts)
        measurements = []
    
        temp = {}
        temp["measurement"] = "battery"
        
        # temp["reading"] = res["battery"]
        temp["reading"] = 74       ##placeholder dragon

        temp["unit"] = "percent"
        measurements.append(temp)

        temp = {}
        temp["measurement"] = "temperature"
        temp["reading"] = res["temp"]
        temp["unit"] = "celcius"
        measurements.append(temp)

        temp = {}
        temp["measurement"] = "CO"
        temp["reading"] = res["co"]
        temp["unit"] = "ppm"
        measurements.append(temp)

        temp = {}
        temp["measurement"] = "humidity"
        temp["reading"] = res["humid"]
        temp["unit"] = "percent"
        measurements.append(temp)

        temp = {}
        temp["measurement"] = "AirQualityIndex"
        temp["reading"] = res["iaq"]
        temp["unit"] = "score"
        measurements.append(temp)

        temp = {}
        temp["measurement"] = "PM2.5"
        temp["reading"] = res["pm25"]
        temp["unit"] = "count"
        measurements.append(temp)

        temp = {}
        temp["measurement"] = "PM1.0"
        temp["reading"] = res["pm1"]
        temp["unit"] = "count"
        measurements.append(temp)

        # payload["battery"] = "74"
        # payload["co"] = res["co"]
        # payload["temp"] = res["temp"]
        # payload["humid"] = res["humid"]
        # payload["iaq"] = res["iaq"]
        # payload["pm1"] = res["pm1"]
        # payload["pm25"] = res["pm25"]

        payload["measurements"] = measurements
        
        print(payload)

        col = db.livereadings
        data_id = col.insert_one(payload).inserted_id
        print(data_id)


    

    resraw = request.get_data()
    # print (resraw)

##    args = request.args
##    form = request.form
##    values = request.values

##    print (args)
##    print (form)
##    print (values)

##    sres = request.form.to_dict()
 

    status = {}
    status["server"] = "up"
    status["message"] = "some random message here"
    status["request"] = res 

    statusjson = json.dumps(status)

    print(statusjson)

    js = "<html> <body>OK THIS WoRKS</body></html>"

    resp = Response(statusjson, status=200, mimetype='application/json')
    ##resp.headers['Link'] = 'http://google.com'

    return resp



@app.route("/dummyJson", methods=['GET', 'POST'])
def dummyJson():

    # print(request)

    res = request.get_json()
    print (res)

    resraw = request.get_data()
    # print (resraw)

##    args = request.args
##    form = request.form
##    values = request.values

##    print (args)
##    print (form)
##    print (values)

##    sres = request.form.to_dict()
 

    status = {}
    status["server"] = "up"
    status["message"] = "some random message here"
    status["request"] = res 

    statusjson = json.dumps(status)

    print(statusjson)

    js = "<html> <body>OK THIS WoRKS</body></html>"

    resp = Response(statusjson, status=200, mimetype='application/json')
    ##resp.headers['Link'] = 'http://google.com'

    return resp





if __name__ == "__main__":
    # app.run(debug=True, host = 'localhost', port = 8005)
    app.run(debug=True, host = '52.116.36.178', port = 8001)




# data = getAllReadings()
# for d in data:
#     print(d)
