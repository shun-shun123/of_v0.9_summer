# coding: utf-8
from httpClient import HttpClient
from scrape import Pictures

httpClient = HttpClient()
httpClient.GET()

# from jsonController import JsonController
# jsonController = JsonController()
# entranceStationNameList, exitStationNameList = jsonController.listOfStationName()
# for eachEntrance in entranceStationNameList:
#     scrapeEntrancePictures = Pictures(eachEntrance + "駅")
#     scrapeEntrancePictures.execute()
# for eachExit in exitStationNameList:
#     scrapeExitPictures = Pictures(eachExit + "駅")
#     scrapeExitPictures.execute()
