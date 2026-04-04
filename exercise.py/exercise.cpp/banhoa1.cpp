// cspell:disable
#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;

class HangHoa{
protected:
    string ma, ten, nhasx;
    double gia;
public:
    HangHoa(string m, string t, string nsx, double g): ma(m) ,ten(t), nhasx(nsx) , gia(g){}
    virtual ~HangHoa(){
        cout<<"Dang gia phong bo nho cho: "<<ten<<endl;
    }
    virtual void xuat(){
        cout<<"Thong tin chi tiet: \n";
        cout<<"Ma: "<<ma<<" | "<<" Ten: "<<ten<<" | "<<" Nha san xuat: "<<nhasx<<" | "<<"Gia: "<<gia<<endl;
    }
};

class HangDienMay : public HangHoa{
        string tg_baohanh;
        double dien_ap, cong_suat;
    public:
    HangDienMay(string m, string t, string nsx, double g, string tgbh, double dp, double cs) : HangHoa( m,  t,  nsx, g),tg_baohanh(tgbh), dien_ap(dp) , cong_suat(cs) {}
    ~HangDienMay(){
        cout<<" Dang giai phong bo nho cho Hang Dien May "<<endl;
    }
    void xuat() override {
        HangHoa::xuat();{
            cout<<" Thoi Gian Bao Hanh: "<<tg_baohanh<<endl;
            cout<<" Dien ap: "<<dien_ap<<endl;
            cout<<" Cong_suat: "<<cong_suat<<endl;
        };
        
    };
};
class HanhSanhSu : public HangHoa{
        string loai_nguyenlieu;
    public:
        HanhSanhSu(string m, string t, string nsx, double g , string lnl)
        :HangHoa(m,t,nsx,g), loai_nguyenlieu(lnl){}
    ~HanhSanhSu(){
        cout<<"Dang xoa du lieu chi tiet cua: "<<ten<<endl;
    }
    void xuat() override{
    HangHoa::xuat();{
        cout<<" Loai nguyen lieu: "<<loai_nguyenlieu;
    }
    }
};

class HangThucPham : public HangHoa{
    string ngay_sx;
    string ngay_hethan;
    public:
    HangThucPham(string m, string t, string nsx, double g,string ngsx, string nhh)
    :HangHoa(m,t,nsx,g), ngay_sx(ngsx), ngay_hethan(nhh){}
    ~HangThucPham(){
        cout<<" Dang xoa du lieu chi tiet cua: "<<ten<<endl;
    }
    void xuat() override{
        HangHoa::xuat();{
            cout<<"Ngay san xuat: "<<ngay_sx<<endl;
            cout<<"Ngay het han; "<<ngay_hethan<<endl;
        }
    }
};

int main(){
    vector<HangHoa*>kho;
    int choice;
    string ma, ten, nhasx;
    double gia;
    while(true){
        cout<<"====== QUAN LY HANG HOA ======\n";
        cout<<"1. Them HangDienMay\n";
        cout<<"2. Them HangHanhSu\n";
        cout<<"3. Them HangThucPham\n";
        cout<<"4. HienThiDanhSach\n";
        cout<<"5. Exit va giai phong bo nho!\n";
        cout<<"Nhap lua chon: \n"; cin>>choice;

        if(choice==5) break;
        if(choice ==4){
            cout<<"Hien thi danh sach toan bo kho: \n";
            for(auto h: kho) h->xuat();
            continue;
        }
        if(choice == 1 || choice == 2 || choice == 3){
            string ma, ten, nsx;
            double gia;
            cout<<" Nhap ma: "; cin>>ma;
            cout<<" Nhap ten: "; cin.ignore(); getline(cin, ten);
            cout<<" Nhap nha san xuat: ";cin>>nsx;
            cout<<" Nhap Gia: "; cin>>gia;
        
        if(choice==1){
        string tg_baohanh;
        double dien_ap, cong_suat;
        cout<<" Nhap thoi gian bao hanh: "; cin>>tg_baohanh;
        cout<<" Nhap dien ap (V): "; cin>>dien_ap;
        cout<<" Nhap cong suat (W): "; cin>>cong_suat;
        kho.push_back(new HangDienMay( ma, ten, nsx, gia,  tg_baohanh , dien_ap, cong_suat));
        cout<<"Da them thanh cong!"<<endl;
        }
        
        else if(choice ==2 ){
            string lnl;
            cout<<"Nhap loai nguyen lieu: ";cin>>lnl;
            kho.push_back(new HanhSanhSu(ma, ten, nsx, gia,lnl));
            cout<<"Da them thanh cong!"<<endl; 
        }
        else if(choice ==3){
             string ngay_sx;
             string ngay_hethan;
             cout<<" Nhap ngay san xuat: "; cin>>ngay_sx;
             cout<<" Nhap ngay het han: "; 
             cin>>ngay_hethan;
             kho.push_back(new HangThucPham(ma, ten, nsx, gia ,ngay_sx, ngay_hethan ));
        }
        
    }
}
cout<<"Bat dau huy doi tuong\n";
for(auto h: kho) delete h;
return 0;
}