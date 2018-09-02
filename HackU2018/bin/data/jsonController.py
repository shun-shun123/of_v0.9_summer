# coding: utf-8
import json

f = open("data.json", "r")
data = json.load(f)

class JsonController:
    data = None
    exitName = "exitStationName"
    entranceName = "entranceStationName"
    def __init__(self):
        f = open("data.json", "r")
        self.data = json.load(f)
    
    def listOfStationName(self):
        entranceStationName = []
        exitStationName = []
        for each in self.data:
            entranceStationName.append(each[self.entranceName])
            exitStationName.append(each[self.exitName])
        return entranceStationName, exitStationName