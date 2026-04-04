// cspell:disable
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- LỚP CHA ---
class HangHoa {
protected:
    string ma, ten;
    double gia;
public:
    HangHoa(string m, string t, double g) : ma(m), ten(t), gia(g) {}

    // Destructor ảo để dọn dẹp sạch bộ nhớ
    virtual ~HangHoa() {
        cout << "Dang giai phong hang: " << ten << endl;
    }

    virtual void xuat() {
        cout << ma << " | " << ten << " | Gia: " << gia;
    }
};

// --- CÁC LỚP CON ---
class HangDienMay : public HangHoa {
    int congSuat;
public:
    HangDienMay(string m, string t, double g, int cs) : HangHoa(m, t, g), congSuat(cs) {}
    ~HangDienMay() { cout << "(Huy chi tiet Dien may)" << endl; }

    void xuat() override {
        HangHoa::xuat();
        cout << " | Cong suat: " << congSuat << "W" << endl;
    }
};

class HangThucPham : public HangHoa {
    string hsd;
public:
    HangThucPham(string m, string t, double g, string han) : HangHoa(m, t, g), hsd(han) {}
    ~HangThucPham() { cout << "(Huy chi tiet Thuc pham)" << endl; }

    void xuat() override {
        HangHoa::xuat();
        cout << " | HSD: " << hsd << endl;
    }
};

// --- CHƯƠNG TRÌNH CHÍNH ---
int main() {
    vector<HangHoa*> kho;
    int luaChon;

    while (true) {
        cout << "\n=== MENU QUAN LY KHO ===" << endl;
        cout << "1. Them Hang Dien May" << endl;
        cout << "2. Them Hang Thuc Pham" << endl;
        cout << "3. Xuat danh sach trong kho" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        if (luaChon == 0) break;

        if (luaChon == 1 || luaChon == 2) {
            string m, t;
            double g;
            cout << "Nhap ma: "; cin >> m;
            cout << "Nhap ten: "; cin.ignore(); getline(cin, t);
            cout << "Nhap gia: "; cin >> g;

            if (luaChon == 1) {
                int cs;
                cout << "Nhap cong suat (W): "; cin >> cs;
                kho.push_back(new HangDienMay(m, t, g, cs));
            } else {
                string hsd;
                cout << "Nhap Han su dung: "; cin >> hsd;
                kho.push_back(new HangThucPham(m, t, g, hsd));
            }
            cout << "=> Da them thanh cong!" << endl;
        } 
        else if (luaChon == 3) {
            cout << "\n--- DANH SACH TRONG KHO ---" << endl;
            if (kho.empty()) cout << "Kho dang trong!" << endl;
            for (auto h : kho) {
                h->xuat(); // ĐA HÌNH: Tu dong goi dung ham cua tung loai
            }
        } 
        else {
            cout << "Lua chon khong hop le!" << endl;
        }
    }

    // Giai phong bo nho truoc khi thoat
    for (auto h : kho) delete h;
    kho.clear();

    cout << "Tam biet!" << endl;
    return 0;
}