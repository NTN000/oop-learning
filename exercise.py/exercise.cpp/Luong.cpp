// cspell:disable
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

/// Tao Class
class Nhanvien {
    private:
        string tenNhanVien;
        double luongCoBan;
        double heSoLuong;
        double LuongMax=10000000;
        double maNhanVien;
    
/// Constructor
    public:
        Nhanvien(string ten,double maNhanVien, double l, double hsl){
            this->tenNhanVien=ten;
            this->luongCoBan=l;
            this->heSoLuong=hsl;
            this->maNhanVien=maNhanVien;
            
        }
/// Set and Get   
    string gettenNhanVien() const{return tenNhanVien; }
    double getluongCoBan() const{return luongCoBan;}
    double getheSoLuong() const{return heSoLuong;}
    double getmaNhanVien() const{return maNhanVien;}
    void settenNhanVien(string tenNhanVien) {this->tenNhanVien=tenNhanVien;}
    void setluongCoBan(double luongCoBan) {this->luongCoBan=luongCoBan;}
    void setheSoLuong(double heSoLuong) {this->heSoLuong=heSoLuong;}
    void setmaNhanVien(double maNhanVien) {this->maNhanVien=maNhanVien;} // ĐÃ SỬA: Thêm chữ 'set' vào tên hàm
     /// METHODS
       
        /// tinhLuong
        double tinhLuong(){

            return luongCoBan*heSoLuong;
        }
        // tang luong
        bool TangLuong(double heSomoi){
            double HeSoLuongMoi = heSoLuong+heSomoi;
            double Luongskt = luongCoBan*HeSoLuongMoi;
            if(Luongskt>LuongMax){
                cout<<"Pls hay thay doi Hslm!";
                return false;
            }
            this->heSoLuong=HeSoLuongMoi;
            cout<<"Luong moi sau khi tang: "<<Luongskt<<endl;
            return true;
        };
        /// in thong tin
        void display(){
            cout<<" TenNhanVien: "<<tenNhanVien<<" | "<<"LuongCoban: "<<" | "<<luongCoBan<<" | "<<" HeSoLuong: "<<heSoLuong<<endl;
        }

};
int main(){
    string tenNhanVien;
    double luongCoBan;
    double heSoLuong;
     double maNhanVien;
     double LuongMax=10000000;
    vector<Nhanvien>danh_sachnv;
    int choice;
    while(true){
        cout<<" ==== QUAN_LY_NHAN_VIEN ====\n"; 
        cout<<"1. ThemNhanVien\n";
        cout<<"2. HienThiDanhSachNhanVien\n";
        cout<<"3. TangLuong\n";
        cout<<"4. Exit\n";
        cout<<"Nhap lua chon:\n ";
        cin>>choice;

    if(choice==4){
        cout<<"GOODBYE!\n";
        break;
    }
    if(choice==1){
        cout<<"ThemNhanVien:\n";
        cout<<"----------------\n";
        cin.ignore();
        cout<<"TenNhanVien: ";getline(cin,tenNhanVien);

        bool bitrung;
        do{
        bitrung=false;
        cout<<"MaNhanVien: ";cin>>maNhanVien;
        for(int i=0 ;i<danh_sachnv.size(); i++){
            if(danh_sachnv[i].getmaNhanVien() == maNhanVien){
                cout<<"Trung maNhanVien. Vuilongnhaplai!\n";
                bitrung=true;
                break;
            }
        }
        }while(bitrung);

        do{
        cout<<"luongCoBan:  (Toi da:"<<LuongMax<<"):"; cin>>luongCoBan;
        if(luongCoBan>LuongMax){
            cout<<"Loi: Luong co Ban ko dc lon hon Luong Max!\n";
        }
        }while(luongCoBan>LuongMax);

        cout<<"He So Luong: "; cin>>heSoLuong;
        
        Nhanvien NhanVien_nv(tenNhanVien,maNhanVien, luongCoBan,heSoLuong );
        danh_sachnv.push_back(NhanVien_nv);
    }
    if(choice==2){
        if(danh_sachnv.empty()){
            cout<<"Danh sach Nhan Vien trong!!!\n";
            continue;}
        else{
        cout<<"Hien Thi Toan Bo Danh Sach Nhan Vien: \n";
        cout<<"=================\n";
        for(int i=0; i < danh_sachnv.size() ;i++){
            danh_sachnv[i].display();
        }}
    }
  if(choice == 3) {
    double maTim;
    bool timThay = false;

    cout << "--- Tang Luong Nhan Vien ---\n";
    cout << "Nhap Ma Nhan Vien can tang luong: "; cin >> maTim;

    // Duyệt danh sách để tìm nhân viên
    for(int i = 0; i < danh_sachnv.size(); i++) {
        if(danh_sachnv[i].getmaNhanVien() == maTim) {
            timThay = true;
            double heSoTang;
            
            cout << "Tim thay nhan vien: " << danh_sachnv[i].gettenNhanVien() << endl;
            cout << "Nhap he so luong muon tang THÊM (vi du: 0.5): "; 
            cin >> heSoTang;

            // Gọi hàm TangLuong từ Class và truyền giá trị vào
            if(danh_sachnv[i].TangLuong(heSoTang)) {
                cout << "=> Cap nhat luong thanh cong!\n";
            } else {
                cout << "=> Cap nhat THAT BAI (vuot muc Luong Max).\n";
            }
            break; 
        }
    }

    if(!timThay) {
        cout << "Loi: Khong tim thay nhan vien co ma " << maTim << endl;
    }
  } 
 } 
 return 0; 
} 