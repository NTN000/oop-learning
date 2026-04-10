#exercise1:
def grid2x2():
    # In hàng ngang
    print("+ - - - + - - - +")
    # In 4 dòng dọc
    for i in range(4):
        print("|       |       |")
    # Lặp lại hàng ngang
    print("+ - - - + - - - +")
    for i in range(4):
        print("|       |       |")
    # Kết thúc bằng hàng ngang
    print("+ - - - + - - - +")

grid2x2()


#ex2:
def grid4x4():
    for row in range(4):
        print("+ - - - + - - - + - - - + - - - +")
        for i in range(4):
            print("|       |       |       |       |")
    print("+ - - - + - - - + - - - + - - - +")

grid4x4()