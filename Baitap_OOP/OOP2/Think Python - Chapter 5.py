    #THINK AND PYTHON, CHAPTER 1:
    #Exercise 5.1:

import time

# Lấy số giây kể từ epoch (1/1/1970)
current_time = time.time()

# Tính số ngày kể từ epoch
days = int(current_time // 86400)   # 1 ngày = 86400 giây

# Tính giờ, phút, giây trong ngày hiện tại
seconds_today = int(current_time % 86400)
hours = seconds_today // 3600
minutes = (seconds_today % 3600) // 60
seconds = seconds_today % 60

print("Ngày kể từ epoch:", days)
print("Giờ hiện tại (GMT):", hours, ":", minutes, ":", seconds)