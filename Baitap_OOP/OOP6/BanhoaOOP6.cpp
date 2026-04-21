#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

// =========================================================
// 1. CUSTOM EXCEPTIONS
// =========================================================
class GiaKhongHopLe : public exception {
public:
    const char* what() const throw() { return "Loi: Gia hang hoa phai >= 0!"; }
};

class MaHangTrong : public exception {
public:
    const char* what() const throw() { return "Loi: Ma hang hoa khong duoc de trong!"; }
};

// =========================================================
// 2. ABSTRACT CLASS (Lớp cha trừu tượng)
// =========================================================
class HangHoa {
protected:
    string ma, ten, nhasx;
    double gia;
public:
    HangHoa(string m, string t, string nsx, double g) {
        if (m.empty()) throw MaHangTrong();
        if (g < 0) throw GiaKhongHopLe();
        ma = m; ten = t; nhasx = nsx; gia = g;
    }

    virtual string getLoaiHang() = 0; 
    
    // Getter để lớp KhoHang có thể kiểm tra mã
    string getMa() const { return ma; }

    virtual void xuat() {
        cout << ma << " | " << ten << " | " << getLoaiHang() << " | Gia: " << (long long)gia;
    }

    // Nạp chồng toán tử == để so sánh đối tượng với một mã chuỗi
    bool operator==(const string& maTim) {
        return this->ma == maTim;
    }

    virtual ~HangHoa() {}
};

// =========================================================
// 3. CÁC LỚP CON CỤ THỂ
// =========================================================
class HangDienMay : public HangHoa {
    string tg_baohanh;
    double dien_ap;
public:
    HangDienMay(string m, string t, string nsx, double g, string tgbh, double dp) 
        : HangHoa(m, t, nsx, g), tg_baohanh(tgbh), dien_ap(dp) {}

    string getLoaiHang() override { return "Dien May"; }

    void xuat() override {
        HangHoa::xuat();
        cout << " | BH: " << tg_baohanh << " | " << dien_ap << "V" << endl;
    }
};

class HangThucPham : public HangHoa {
    string ngay_hethan;
public:
    HangThucPham(string m, string t, string nsx, double g, string nhh)
        : HangHoa(m, t, nsx, g), ngay_hethan(nhh) {}

    string getLoaiHang() override { return "Thuc Pham"; }

    void xuat() override {
        HangHoa::xuat();
        cout << " | HSD: " << ngay_hethan << endl;
    }
};

// =========================================================
// 4. LỚP QUẢN LÝ (Kho Hang)
// =========================================================
class KhoHang {
private:
    vector<HangHoa*> danhSach;
public:
    // Hàm mới: Kiểm tra xem mã đã tồn tại hay chưa
    bool kiemTraTrungMa(string maMoi) {
        for (auto item : danhSach) {
            if (*item == maMoi) return true; // Sử dụng operator==
        }
        return false;
    }

    void themHang(HangHoa* h) {
        danhSach.push_back(h);
    }

    void hienThi() {
        if (danhSach.empty()) {
            cout << "=> Kho dang trong!\n";
            return;
        }
     cout << "\n=======================================================\n";
    cout << "Ma | Ten Hang | Loai Hang | Thong tin chi tiet\n";
    cout << "-------------------------------------------------------\n";
    
    for (auto h : danhSach) {
        h->xuat(); // Gọi hàm xuất đã đơn giản hóa ở trên
    }
    
    cout << "=======================================================\n";

    }

    ~KhoHang() {
        for (auto h : danhSach) delete h;
    }
};

// =========================================================
// 5. CHƯƠNG TRÌNH CHÍNH
// =========================================================
int main() {
    KhoHang kho;
    int choice;

    while (true) {
        try {
            cout << "\n--- HE THONG QUAN LY KHO ---";
            cout << "1. Them Dien May\n"; 
            cout << "2. Them Thuc Pham\n"; 
            cout << "3. Xem Kho\n"; 
            cout << "4. Thoat\n";
            cout << "Lua chon: "; 
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
 
            if (choice == 4) break;
            if (choice == 3) { kho.hienThi(); continue; }
            if (choice < 1 || choice > 4) continue;

            string ma;
            // KIỂM TRA MÃ NGAY LẬP TỨC
            while (true) {
                cout << "Nhap ma hang: "; cin >> ma;
                if (ma.empty()) {
                    cout << "!!! Loi: Ma khong duoc de trong!\n";
                } else if (kho.kiemTraTrungMa(ma)) {
                    cout << "!!! Loi: Ma [" << ma << "] da ton tai. Vui long nhap ma khac!\n";
                } else {
                    break; // Mã hợp lệ, thoát vòng lặp nhập mã
                }
            }

            string ten, nsx; double gia;
            cout << "Ten hang: "; cin.ignore(); getline(cin, ten);
            cout << "Nha san xuat: "; getline(cin, nsx);
            cout << "Gia ban: "; cin >> gia;

            if (choice == 1) {
                string tgbh; double dp;
                cout << "Thoi gian bao hanh: "; cin >> tgbh;
                cout << "Dien ap (V): "; cin >> dp;
                kho.themHang(new HangDienMay(ma, ten, nsx, gia, tgbh, dp));
            } else if (choice == 2) {
                string nhh;
                cout << "Ngay het han (dd/mm/yyyy): "; cin >> nhh;
                kho.themHang(new HangThucPham(ma, ten, nsx, gia, nhh));
            }

            cout << "\n=> [THANH CONG] Da them hang hoa vao kho.\n";

        } catch (const exception& e) {
            cout << "\n!!! ERROR: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    cout << "\nCam on ban da su dung phan mem!";
    return 0;
}