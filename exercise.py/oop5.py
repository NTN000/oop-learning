# cspell:disable

# --- BƯỚC 1: ĐỊNH NGHĨA LỚP CHA ---
class CanBo:
    def __init__(self, ho_ten, tuoi, gioi_tinh, dia_chi):
        self.ho_ten = ho_ten
        self.tuoi = tuoi
        self.gioi_tinh = gioi_tinh
        self.dia_chi = dia_chi

    def hien_thi_thong_tin(self):
        # f-string giúp căn lề thẳng hàng: {biến:độ_rộng}
        print(f"Họ tên: {self.ho_ten:15} | Tuổi: {self.tuoi:3} | GT: {self.gioi_tinh:5} | ĐC: {self.dia_chi:15}", end=" | ")

# --- BƯỚC 2: CÁC LỚP CON KẾ THỪA ---

class CongNhan(CanBo):
    def __init__(self, ho_ten, tuoi, gioi_tinh, dia_chi, bac):
        # super() gọi hàm khởi tạo của lớp CanBo để nạp 4 thông tin chung
        super().__init__(ho_ten, tuoi, gioi_tinh, dia_chi)
        self.bac = bac

    def hien_thi_thong_tin(self):
        super().hien_thi_thong_tin() # Gọi hàm in của cha
        print(f"Bậc: {self.bac}/10")

class KySu(CanBo):
    def __init__(self, ho_ten, tuoi, gioi_tinh, dia_chi, nganh_dao_tao):
        super().__init__(ho_ten, tuoi, gioi_tinh, dia_chi)
        self.nganh_dao_tao = nganh_dao_tao

    def hien_thi_thong_tin(self):
        super().hien_thi_thong_tin()
        print(f"Ngành: {self.nganh_dao_tao}")

class NhanVien(CanBo):
    def __init__(self, ho_ten, tuoi, gioi_tinh, dia_chi, cong_viec):
        super().__init__(ho_ten, tuoi, gioi_tinh, dia_chi)
        self.cong_viec = cong_viec

    def hien_thi_thong_tin(self):
        super().hien_thi_thong_tin()
        print(f"Công việc: {self.cong_viec}")

# --- BƯỚC 3: LỚP QUẢN LÝ (QLCB) ---
class QLCB:
    def __init__(self):
        self.danh_sach_can_bo = []

    def them_moi(self, can_bo):
        self.danh_sach_can_bo.append(can_bo)
        print("=> Đã thêm mới thành công!")

    def tim_kiem_theo_ten(self, ten):
        print(f"\nKết quả tìm kiếm cho '{ten}':")
        check = False
        for cb in self.danh_sach_can_bo:
            if ten.lower() in cb.ho_ten.lower():
                cb.hien_thi_thong_tin()
                check = True
        if not check:
            print("Không tìm thấy cán bộ nào.")

    def hien_thi_danh_sach(self):
        print("\n--- TẤT CẢ CÁN BỘ TRONG ĐƠN VỊ ---")
        for cb in self.danh_sach_can_bo:
            cb.hien_thi_thong_tin()

# --- BƯỚC 4: CHƯƠNG TRÌNH CHÍNH (MENU) ---
def main():
    ql = QLCB()
    while True:
        print("\n--- QUẢN LÝ CÁN BỘ ---")
        print("1. Thêm mới cán bộ")
        print("2. Tìm kiếm theo họ tên")
        print("3. Hiển thị danh sách")
        print("4. Thoát")