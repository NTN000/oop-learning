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
        setTuoi(t);
    }

    void setTuoi(int t) {
        if (t < 18 || t > 65) throw TuoiKhongHopLe();
        tuoi = t;
    }

    int getTuoi() const { return tuoi; }
    string getHoTen() const { return hoTen; }

    virtual string mo_ta() = 0;

    // Nạp chồng toán tử << để ghi dữ liệu (Dùng cho cả cout và lưu file)
    friend ostream& operator<<(ostream& os, CanBo& cb) {
        os << cb.hoTen << " | " << cb.tuoi << " tuoi | " << cb.gioiTinh << " | " << cb.mo_ta();
        return os;
    }

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
// 4. LỚP QUẢN LÝ: QLCB (Đã thêm chức năng Đọc File)
// =========================================================
class QLCB {
private:
    vector<CanBo*> danhSach;

public:
    void themMoi(CanBo* cb) {
        danhSach.push_back(cb);
    }

    void hienThi() {
        if (danhSach.empty()) {
            cout << "(Danh sach hien dang trong)\n";
            return;
        }
        for (auto cb : danhSach) cout << *cb << endl;
    }

    // CHỨC NĂNG LƯU FILE (Ghi từ RAM xuống ổ cứng)
    void luuFile(string fileName) {
        ofstream file(fileName); 
        if (file.is_open()) {
            for (auto cb : danhSach) {
                file << *cb << endl; // Ghi đối tượng thành 1 dòng văn bản
            }
            file.close();
            cout << "=> Da LUO file: " << fileName << endl;
        }
    }

    // CHỨC NĂNG ĐỌC FILE (Đọc từ ổ cứng nạp ngược lại RAM)
    void docFile(string fileName) {
        ifstream file(fileName);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                try {
                    // Logic tách chuỗi đơn giản dựa trên dấu " | "
                    size_t p1 = line.find(" | ");
                    size_t p2 = line.find(" tuoi | ");
                    size_t p3 = line.find(" | ", p2 + 8);
                    size_t p4 = line.find(" bac ", p3);

                    if (p1 != string::npos && p2 != string::npos) {
                        string ten = line.substr(0, p1);
                        int tuoi = stoi(line.substr(p1 + 3, p2 - (p1 + 3)));
                        string gt = line.substr(p2 + 8, p3 - (p2 + 8));
                        int bac = stoi(line.substr(p4 + 5));

                        // "Hồi sinh" đối tượng và thêm vào danh sách
                        themMoi(new CongNhan(ten, tuoi, gt, "Chua xac dinh", bac));
                    }
                } catch (...) { continue; } // Bỏ qua dòng lỗi
            }
            file.close();
            cout << "=> Da DOC file: " << fileName << endl;
        } else {
            cout << "=> Khong tim thay file de doc!\n";
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
        // 1. Tạo dữ liệu ban đầu
        ql.themMoi(new CongNhan("Nguyen Van A", 30, "Nam", "HN", 5));
        ql.themMoi(new CongNhan("An Van C", 40, "Nam", "DN", 7));

        cout << "--- Danh sach hien tai tren RAM ---\n";
        ql.hienThi();

        // 2. Lưu xuống ổ cứng
        ql.luuFile("database.txt");

        // 3. Xóa dữ liệu cũ hoặc tạo đối tượng quản lý mới để kiểm chứng
        QLCB ql_moi;
        cout << "\n--- Bat dau doc du lieu tu file vao RAM ---\n";
        ql_moi.docFile("database.txt");
        
        cout << "--- Danh sach sau khi phuc hoi ---\n";
        ql_moi.hienThi();

    } catch (const exception& e) {
        cout << "ERROR: " << e.what() << endl;
    }

    return 0;
}