
class Point:
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
print(d_BO)


        
