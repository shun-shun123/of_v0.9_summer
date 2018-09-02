# coding: UTF-8
import urllib.request
import bs4
import os

class Pictures:
    url = ""
    station_name = ""
    encoding_list = ["utf-8", "utf_8", "euc_jp","euc_jis_2004", "euc_jisx0213", "shift_jis",
                    "shift_jis_2004","shift_jisx0213", "iso2022jp","iso2022_jp_1", "iso2022_jp_2",
                    "iso2022_jp_3","iso2022_jp_ext","latin_1", "ascii"]
    def __init__(self, station_name):
        self.url = "https://search.yahoo.co.jp/image/search?ei=UTF-8&fr=sfp_as&aq=-1&oq=&ts=8&p=" + urllib.parse.quote_plus(station_name, encoding="utf-8") + "&meta=vc%3D"
        self.station_name = station_name
    
    def __getHtml(self):
        request = urllib.request.Request(self.url)
        response = urllib.request.urlopen(request)
        html = response.read()
        html = self.__encodeHtml(html)
        return html
    
    def __encodeHtml(self, html):
        for enc in self.encoding_list:
            try:
                html.decode(enc)
                break
            except:
                enc = None
        if enc != None:
            html = html.decode(enc)
            return html

    def execute(self):
        resources = []
        html = self.__getHtml()
        soup = bs4.BeautifulSoup(html, "html.parser")
        elements = soup.findAll('img')
        self.__savePictures(elements)

    def __savePictures(self, elements):
        num = 0
        os.makedirs("./" + str(self.station_name), exist_ok=True)
        for e in elements:
            # 6枚で終了
            if num == 6:
                break
            request = urllib.request.urlopen(e['src'])
            with open("./" + str(self.station_name) + "/pic" + str(num) + ".png", "wb") as f:
                f.write(request.read())
            num += 1

