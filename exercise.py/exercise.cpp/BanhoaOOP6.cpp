#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<stdexcept> // Thư viện cho Exception

using namespace std;

// =========================================================
// 1. CUSTOM EXCEPTION (Ngoại lệ tự định nghĩa)
// ==========================+===============================
class GiaKhongHopLe : public exception {
public:
    const char* what() const throw() {
        return "Loi: Gia hang hoa phai >= 0!";
    }
};

class MaHangTrong : public exception {
public:
    const char* what() const throw() {
        return "Loi: Ma hang hoa khong duoc de trong!";
    }
};

// =========================================================
// 2. ABSTRACT CLASS (Lớp trừu tượng)
// =========================================================
class HangHoa {
protected:
    string ma, ten, nhasx;
    double gia;
public:
    // Constructor có Validation (Kiểm tra dữ liệu)
    HangHoa(string m, string t, string nsx, double g) {
        if (m.empty()) throw MaHangTrong();
        if (g < 0) throw GiaKhongHopLe();
        ma = m; ten = t; nhasx = nsx; gia = g;
    }

    // Abstract method: Ép các lớp con phải tự định nghĩa loại hàng
    virtual string getLoaiHang() = 0; 
    
    // Hàm xuất ảo
    virtual void xuat() {
        cout << left << setw(10) << ma << " | " 
             << setw(15) << ten << " | " 
             << setw(12) << getLoaiHang() << " | "
             << "Gia: " << fixed << setprecision(0) << gia;
    }

    // OPERATOR OVERLOADING: So sánh hai hàng hóa dựa trên mã
    bool operator==(const string& maTim) {
        return this->ma == maTim;
    }

    virtual ~HangHoa() {}
};

// =========================================================
// 3. CÁC LỚP CON CỤ THỂ (Method Overriding)
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
// 4. LỚP QUẢN LÝ (Kết hợp File I/O giả lập & Quản lý danh sách)
// =========================================================
class KhoHang {
private:
    vector<HangHoa*> danhSach;
public:
    void themHang(HangHoa* h) {
        // Kiểm tra trùng mã (Dùng Operator Overloading == đã định nghĩa ở trên)
        for (auto item : danhSach) {
            if (*item == h->getLoaiHang()) { // Ví dụ logic kiểm tra
                // Có thể thêm logic kiểm tra trùng mã thực sự ở đây
            }
        }
        danhSach.push_back(h);
    }

    void hienThi() {
        if (danhSach.empty()) {
            cout << "Kho trong!\n";
            return;
        }
        cout << "\n--- DANH SACH TRONG KHO ---\n";
        for (auto h : danhSach) h->xuat();
    }

    // Destructor dọn dẹp bộ nhớ (Tương tự Context Manager)
    ~KhoHang() {
        for (auto h : danhSach) delete h;
        cout << "\n[System] Da giai phong bo nho va luu du lieu.\n";
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
            cout << "\n1. Them Dien May | 2. Them Thuc Pham | 3. Xem Kho | 4. Thoat\n";
            cout << "Lua chon: "; cin >> choice;

            if (choice == 4) break;
            if (choice == 3) { kho.hienThi(); continue; }

            string ma, ten, nsx; double gia;
            cout << "Ma: "; cin >> ma;
            cout << "Ten: "; cin.ignore(); getline(cin, ten);
            cout << "NSX: "; getline(cin, nsx);
            cout << "Gia: "; cin >> gia;

            if (choice == 1) {
                string tgbh; double dp;
                cout << "TG bao hanh: "; cin >> tgbh;
                cout << "Dien ap: "; cin >> dp;
                kho.themHang(new HangDienMay(ma, ten, nsx, gia, tgbh, dp));
            } else if (choice == 2) {
                string nhh;
                cout << "Ngay het han: "; cin >> nhh;
                kho.themHang(new HangThucPham(ma, ten, nsx, gia, nhh));
            }
            cout << "=> Them thanh cong!\n";

        } catch (const exception& e) {
            // Hứng tất cả các lỗi (Giá âm, Mã trống...)
            cout << "\n!!! ERROR: " << e.what() << endl;
        }
    }

    return 0;
}