# Bài 1
print(42*60 + 42)

# Bài 2
print(10/1.61)

# Bài 3
time = 42*60 + 42        # tổng giây
miles = 10/1.61
pace = time/miles        # giây mỗi mile
print(int(pace//60), "phút", int(pace%60), "giây mỗi mile")
print(miles/(time/3600), "miles/giờ")