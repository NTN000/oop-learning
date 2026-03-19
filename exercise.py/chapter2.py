import math

#ex1
r = 5
volume = (4/3) * math.pi * r**3
print("Thể tích hình cầu:", volume)

#exe2:
cover_price = 24.95
discount_price = cover_price * 0.6
copies = 60

total_books = discount_price * copies
shipping = 3 + (copies - 1) * 0.75
total_cost = total_books + shipping

print("Tổng chi phí:", total_cost)

#exe3:
import datetime

start = datetime.datetime(2026, 3, 19, 6, 52)

easy_pace = 8*60 + 15   # giây/mile
tempo_pace = 7*60 + 12  # giây/mile

total_seconds = 1*easy_pace + 3*tempo_pace + 1*easy_pace
end = start + datetime.timedelta(seconds=total_seconds)

print("Về nhà lúc:", end.time())