from httpClient import HttpClient
import time

httpClient = HttpClient()
while (True):
    httpClient.GET()
    time.sleep(5000)