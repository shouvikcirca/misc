import requests
import sys
from bs4 import BeautifulSoup
import os

s = sys.argv[1]


r = requests.get(s)
soup = BeautifulSoup(r.text, 'html.parser')


t1 = soup.find_all(id="abs")
t1 = soup.findAll("a", {"class": "mobile-submission-download"})


downloadurl = "https://arxiv.org"
for h in t1:
    downloadurl+=(str(h.get('href'))+'.pdf')



heading = str(soup.findAll("h1", {"class": "title mathjax"})[0].get_text())


heading = heading.split(':')
heading = heading[1:]

finalheadinglist = []
for i in heading:
    finalheadinglist.extend(i.split(' '))


finalheadinglist = ('_').join(finalheadinglist)+".pdf"



execline = 'curl -o '+finalheadinglist+" "+downloadurl


print(execline)

os.system(execline)
