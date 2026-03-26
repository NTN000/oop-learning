
'''class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

A = Point(3,4)
print(A.x, A.y)

x = int(input("Enter x:"))
y = int(input("Enter y:"))
B = Point(x,y)
print(B.x, B.y)

C = Point(-B.x , -B.y)
print(C.x, C.y)

d_BO = (B.x**2 + B.y**2)**0.5
print(d_BO)'''


'''class SieuNhan:
    def __init__(self, ten, vu_khi, mau_sac):
        self.ten = ten
        self.vu_khi = vu_khi
        self.mau_sac = mau_sac

A = SieuNhan("A" , "kiem" , "do")
print(A.ten, A.vu_khi, A.mau_sac)

B= SieuNhan("B" , "sung" , "xanh")
print(B.ten, B.vu_khi, B.mau_sac)'''

''''
#1 Định nghĩa lớp siêu nhân
class SieuNhan:
    def __init__(self , ten, vu_khi, mau_sac):
        self.ten = ten
        self.vu_khi = vu_khi
        self.mau_sac = mau_sac

#2 Tạo danh sách siêu nhân
danh_sach_sieu_nhan = []

#3 Nhập thông tin siêu nhân từ bàn phím
while True:
    ten = input("Nhập tên siêu nhân (hoặc 'exit' để dừng): ")
    if ten.lower() == 'exit':
        break
    vu_khi = input("Nhập vũ khí của siêu nhân: ")
    mau_sac = input("Nhập màu sắc của siêu nhân: ")
    
    #4 Tạo đối tượng siêu nhân và thêm vào danh sách
    sieu_nhan = SieuNhan(ten, vu_khi, mau_sac)
    danh_sach_sieu_nhan.append(sieu_nhan)

#5 In thông tin của tất cả siêu nhân trong danh sách
print (20*"-")
print("\nDanh sách siêu nhân:")
for sieu_nhan in danh_sach_sieu_nhan:
    print(f"Tên: {sieu_nhan.ten}, Vũ khí: {sieu_nhan.vu_khi}, Màu sắc: {sieu_nhan.mau_sac}")
'''
        
    


        

