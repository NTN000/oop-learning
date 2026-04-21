#include <iostream>
#include <vector>
#include <string>
#include <fstream>   // Thư viện để lưu/đọc file
#include <algorithm> // Thư viện để sắp xếp sort()
#include <stdexcept>

using namespace std;

// =========================================================
// 1. CUSTOM EXCEPTIONS
// =========================================================
class TuoiKhongHopLe : public exception {
    const char* what() const throw() { return "Loi: Tuoi phai tu 18 den 65!"; }
};

class BacKhongHopLe : public exception {
    const char* what() const throw() { return "Loi: Bac cong nhan phai tu 1 den 10!"; }
};

// =========================================================
// 2. ABSTRACT BASE CLASS: CanBo
// =========================================================
class CanBo {
protected:
    string hoTen, gioiTinh, diaChi;
    int tuoi;

public:
    CanBo(string ten, int t, string gt, string dc) : hoTen(ten), gioiTinh(gt), diaChi(dc) {
        setTuoi(t); // Dùng setter để kiểm tra ngay lúc khởi tạo
    }

    // @property + validation: Setter cho Tuổi
    void setTuoi(int t) {
        if (t < 18 || t > 65) throw TuoiKhongHopLe();
        tuoi = t;
    }

    int getTuoi() const { return tuoi; }
    string getHoTen() const { return hoTen; }

    // Abstract method: mo_ta()
    virtual string mo_ta() = 0;

    // Tương đương __str__: Nạp chồng toán tử <<
    friend ostream& operator<<(ostream& os, CanBo& cb) {
        os << cb.hoTen << " | " << cb.tuoi << " tuoi | " << cb.gioiTinh << " | " << cb.mo_ta();
        return os;
    }

    // Tương đương __eq__: So sánh họ tên + tuổi
    bool operator==(const CanBo& other) const {
        return (hoTen == other.hoTen && tuoi == other.tuoi);
    }

    // Tương đương __lt__: So sánh theo tên để sắp xếp ABC
    bool operator<(const CanBo& other) const {
        return hoTen < other.hoTen;
    }

    virtual ~CanBo() {}
};

// =========================================================
// 3. LỚP CON: CongNhan
// =========================================================
class CongNhan : public CanBo {
    int bac;
public:
    CongNhan(string ten, int t, string gt, string dc, int b) 
        : CanBo(ten, t, gt, dc) {
        if (b < 1 || b > 10) throw BacKhongHopLe();
        bac = b;
    }

    string mo_ta() override {
        return "Cong nhan bac " + to_string(bac);
    }
};

// =========================================================
// 4. LỚP QUẢN LÝ: QLCB (Với tính năng lưu/đọc File)
// =========================================================
class QLCB {
private:
    vector<CanBo*> danhSach;

public:
    void themMoi(CanBo* cb) {
        danhSach.push_back(cb);
    }

    // Sắp xếp danh sách theo tên (__lt__)
    void sapXep() {
        sort(danhSach.begin(), danhSach.end(), [](CanBo* a, CanBo* b) {
            return *a < *b; 
        });
    }

    void hienThi() {
        for (auto cb : danhSach) cout << *cb << endl;
    }

    // Tính năng mới: Lưu danh sách vào file
    void luuFile(string fileName) {
        ofstream file(fileName); // Mở file để ghi
        if (file.is_open()) {
            for (auto cb : danhSach) {
                file << *cb << endl;
            }
            file.close();
            cout << "=> Da luu danh sach vao file " << fileName << endl;
        }
    }

    ~QLCB() {
        for (auto cb : danhSach) delete cb;
    }
};

// =========================================================
// 5. MAIN
// =========================================================
int main() {
    QLCB ql;
    try {
        ql.themMoi(new CongNhan("Nguyen Van A", 30, "Nam", "HN", 5));
        ql.themMoi(new CongNhan("Tran Thi B", 25, "Nu", "HP", 3));
        ql.themMoi(new CongNhan("An Van C", 40, "Nam", "DN", 7));

        cout << "--- Danh sach goc ---\n";
        ql.hienThi();

        cout << "\n--- Danh sach sau khi sap xep ABC ---\n";
        ql.sapXep();
        ql.hienThi();

        ql.luuFile("danh_sach_can_bo.txt");

    } catch (const exception& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    return 0;
}