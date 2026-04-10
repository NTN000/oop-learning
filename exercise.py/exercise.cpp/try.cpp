#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void kiemTraDinhDang(string pass) {
    if (pass.length() < 6) throw invalid_argument("Mat khau qua ngan!");
}

void luuVaoDB(string pass) {
    bool ketNoiThanhCong = false;
    if (!ketNoiThanhCong) throw runtime_error("Loi ket noi Database!");
}

int main() {
    string mk = "124567";

    try {
        // Luồng chạy chính cực kỳ sạch sẽ
        kiemTraDinhDang(mk);
        luuVaoDB(mk);
        cout << "Thanh cong ruc ro!";
    } 
    catch (const exception& e) {
        // Gom tất cả lỗi vào một chỗ để xử lý
        cout << "LOI ROI: " << e.what() << endl;
    }

    return 0;
}