// cspell:disable
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ================= LỚP CHA: CAN BO =================
class CanBo {
protected:
    string hoTen, gioiTinh, diaChi;
    int tuoi;

public:
    CanBo(string ten, int t, string gt, string dc) 
        : hoTen(ten), tuoi(t), gioiTinh(gt), diaChi(dc) {}

    // Destructor ảo: Cực kỳ quan trọng để dọn dẹp lớp con
    virtual ~CanBo() {
        cout << "[Log] Dang giai phong bo nho cho: " << hoTen << endl;
    }

    string getHoTen() { return hoTen; }

    // Hàm xuất ảo để các lớp con ghi đè (Override)
    virtual void xuat() {
        cout << "Ho ten: " << left << setw(5) << hoTen 
             << " | Tuoi: " << setw(5) << tuoi 
             << " | GT: " << setw(5) << gioiTinh 
             << " | DC: " << diaChi;
    }
};

// ================= CÁC LỚP CON (KẾ THỪA) =================

class CongNhan : public CanBo {
    int bac;
public:
    CongNhan(string ten, int t, string gt, string dc, int b) 
        : CanBo(ten, t, gt, dc), bac(b) {}

    void xuat() override {
        CanBo::xuat();
        cout << " | Nghe: Cong nhan (Bac " << bac << "/10)" << endl;
    }
};

class KySu : public CanBo {
    string nganhDaoTao;
public:
    KySu(string ten, int t, string gt, string dc, string nganh) 
        : CanBo(ten, t, gt, dc), nganhDaoTao(nganh) {}

    void xuat() override {
        CanBo::xuat();
        cout << " | Nghe: Ky su (Nganh: " << nganhDaoTao << ")" << endl;
    }
};

class NhanVien : public CanBo {
    string congViec;
public:
    NhanVien(string ten, int t, string gt, string dc, string cv) 
        : CanBo(ten, t, gt, dc), congViec(cv) {}

    void xuat() override {
        CanBo::xuat();
        cout << " | Nghe: Nhan vien (Viec: " << congViec << ")" << endl;
    }
};

// ================= LỚP QUẢN LÝ (CONTROLLER) =================

class QLCB {
private:
    vector<CanBo*> danhSach;

public:
    // Destructor của lớp Quản lý tự động dọn dẹp vector
    ~QLCB() {
        for (auto cb : danhSach) {
            delete cb; // Kích hoạt Destructor ảo
        }
        danhSach.clear();
        cout << "\n===> Thong bao: Ham huy QLCB da thuc thi nhiem vu! <===" << endl;
    }

    void themMoi(CanBo* cb) {
        danhSach.push_back(cb);
        cout << "=> Da them thanh cong!" << endl;
    }

    void timKiem(string tenTim) {
        bool found = false;
        cout << "\n--- KET QUA TIM KIEM ---" << endl;
        for (auto cb : danhSach) {
            if (cb->getHoTen() == tenTim) {
                cb->xuat();
                found = true;
            }
        }
        if (!found) cout << "Khong tim thay can bo ten: " << tenTim << endl;
    }

    void hienThi() {
        cout << "\n--- DANH SACH TOAN BO CAN BO ---" << endl;
        if (danhSach.empty()) {
            cout << "(Danh sach dang trong)" << endl;
            return;
        }
        for (auto cb : danhSach) {
            cb->xuat(); // Đa hình thực tế ở đây
        }
    }
};

// ================= HÀM MAIN (GIAO DIỆN) =================

int main() {
    QLCB ql;
    int choice;

    while (true) {
        cout << "\n========= MENU QUAN LY =========" << endl;
        cout << "1. Them moi can bo" << endl;
        cout << "2. Tim kiem theo ho ten" << endl;
        cout << "3. Hien thi danh sach" << endl;
        cout << "4. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon: "; cin >> choice;

        if (choice == 4) break;

        if (choice == 1) {
            int loai;
            cout << "Chon loai (1-Cong nhan, 2-Ky su, 3-Nhan vien): "; cin >> loai;
            
            string ten, gt, dc; int tuoi;
            cout << "Ho ten: "; cin.ignore(); getline(cin, ten);
            cout << "Tuoi: "; cin >> tuoi;
            cout << "Gioi tinh: "; cin.ignore(); getline(cin, gt);
            cout << "Dia chi: "; getline(cin, dc);

            if (loai == 1) {
                int bac; cout << "Bac (1-10): "; cin >> bac;
                ql.themMoi(new CongNhan(ten, tuoi, gt, dc, bac));
            } 
            else if (loai == 2) {
                string nganh; cout << "Nganh dao tao: "; cin.ignore(); getline(cin, nganh);
                ql.themMoi(new KySu(ten, tuoi, gt, dc, nganh));
            } 
            else if (loai == 3) {
                string cv; cout << "Cong viec: "; cin.ignore(); getline(cin, cv);
                ql.themMoi(new NhanVien(ten, tuoi, gt, dc, cv));
            }
        } 
        else if (choice == 2) {
            string ten;
            cout << "Nhap ten can tim: "; cin.ignore(); getline(cin, ten);
            ql.timKiem(ten);
        } 
        else if (choice == 3) {
            ql.hienThi();
        }
    }

    cout << "Chuong trinh ket thuc." << endl;
    return 0;
}