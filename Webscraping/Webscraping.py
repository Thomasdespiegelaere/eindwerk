import requests
from bs4 import BeautifulSoup

URL = "https://www.meteo.be/nl/kortrijk"
r = requests.get(URL)

soup = BeautifulSoup(r.content, "html.parser")

x = 0
while x <= 1056:
    tags = soup.find_all(["g"], transform="translate(%d, 0)" % x)     # %d is de variable x
    tijd = tags[0].find_all("text")
    weer = tags[1].find_all(['class_="wwbox"', "title"])
    tijd_str = tijd[0].string
    weer_str = weer[0].string
    if "zon" in weer_str:
        print("succes")
    x = x + 96

