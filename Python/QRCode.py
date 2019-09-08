import qrcode

url = "https://www.xinpianchang.com/u10495092"

print(url)
img = qrcode.make(url)
img.show()