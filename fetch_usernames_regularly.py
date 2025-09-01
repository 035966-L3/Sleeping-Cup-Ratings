import requests
import re
import sys
from datetime import datetime, timezone
from lxml import html
def match(text):
    pattern = r'^\s*(.+?)\s*$'
    matched = re.search(pattern, text)
    if matched:
        return matched.group(1) + "\n"
    else:
        return None
url = "http://8.136.99.126/user/"
users = 0
with open("usernames.txt", "wb") as file:
    while True:
        users = users + 1
        content = requests.get(url + str(users))
        if content.ok == False:
            users = users - 1
            file.write(b"\n")
            file.write(bytes("// Updated at: {}\n".format(datetime.now(timezone.utc)), encoding="utf-8"))
            break
        tree = html.fromstring(content.content)
        element = tree.xpath('/html/body/div/div[3]/div/div[1]/div/div[1]/div/div/div[2]/h1')[0].text_content().strip()
        file.write(bytes(match(element), encoding='utf-8'))
print("OK! {} registered users detected.".format(users))

