// cspell:disable
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;
class CanBo{
    protected:
        string Ho_ten, gioi_tinh;
        int tuoi;
    public:
        CanBo(string ht, string gt, int t):Ho_ten(ht), gioi_tinh(gt), tuoi(t){}
       
        virtual void xuat(){
            cout<<" Ho_ten: "<<Ho_ten<<" Gioi_tinh: "<<gioi_tinh<<" Tuoi: "<<tuoi<<endl;
        }
        virtual ~CanBo(){}

        string getHo_ten (){
            return Ho_ten;
        }
};
class CongNhan : public CanBo{
    int Bac;
    public:
    CongNhan( int t,string ht, string gt, int b):CanBo(ht,gt,t), Bac(b){}
    
    void xuat()override{
        CanBo::xuat();
        cout<<" Bac xep hang: "<<Bac;
    }
    ~CongNhan(){}
};
class KySu:public CanBo{
    string Nganhdt;
    public:
        KySu(string ht, int t, string gt, string ndt):CanBo(ht,gt,t), Nganhdt(ndt){}
    void xuat() override{
        CanBo::xuat();
        cout<<"Nganh dao tao: "<<Nganhdt<<endl;
    }
    ~KySu(){}
};
class Nhanvien:public CanBo{
    string cong_viec;
    public:
    Nhanvien(string ht, int t, string gt, string cv):CanBo(ht,gt,t), cong_viec(cv){}
    void xuat()override{
        CanBo::xuat();
        cout<<" Cong viec: "<<cong_viec<<endl;
    }
    ~Nhanvien(){}
};
class QLCB{
private:
vector<CanBo*>danh_sach;
public:
    ~QLCB(){
        for(auto cb:danh_sach){
            delete cb;
        }
        danh_sach.clear();
        cout<<" Ham huy QLCB da hoat dong!"<<endl;

    }
void themmoi(CanBo*cb){
    danh_sach.push_back(cb);
    cout<<" Da them thanh cong can bo"<<endl;

}
void timkiem(string tentim){
    cout<<"-----TIM KIEM CAN BO----\n";
    bool found = false;
    for(auto cb:danh_sach){
        if(cb->getHo_ten()==tentim){
            cb->xuat();
            found=true;
        }
    }
    if(!found){
            cout<<"Ko tim thay can bo!"<<endl;
};}
void hienthi(){
    if(danh_sach.empty()){
        cout<<"Danh sach trong!\n";
     return;
    }
    else{
        cout<<"===HIen thi danh sach===\n";
        for(auto cb :danh_sach){
            cb->xuat();
        }
    }
}
};
int main(){
    QLCB ql;
    int choice;
    while(true){
        cout<<"===== Quan ly Can Bo ====="<<endl;
        cout<<"1.Them Can Bo( 1.Cong Nhan | 2.KySu | 3.NhanVien):\n";
        cout<<"2.Tim kiem theo ho ten:\n";
        cout<<"3.Hien thi thong tin ve danh sach cac can bo:\n";
        cout<<"4.Thoat khoi truong chinh!\n";
        cout<<"Nhap lua chon: "; cin>>choice;

    if(choice==4){
        cout<<"Thoat khoi truong trinh!\n"<<endl;
        break;
    }

    if(choice==1){
            int loai;
            cout<<" Chon loai (1.Cong nhan | 2.KySu | 3.NhanVien)\n";
            cin>>loai;

            string ten,gt; int t;
            cout<<" Nhap ten: "; cin.ignore(); getline(cin,ten);
            cout<<" Nhap gioi tinh: "; cin.ignore();getline(cin, gt);
            cout<<" Nhap tuoi: "; cin>>t;
            
            if(loai==1){
                int bac;
                cout<<"Nhap Bac(1-10)\n"; cin>>bac;
                ql.themmoi( new CongNhan(t, ten, gt ,bac));
            }
            if(loai==2){
                string ndt;
                cout<<" Nhap nganh dao tao: "; cin>>ndt;
                ql.themmoi(new KySu(ten,t,gt,ndt));
            }   
            if(loai==3){
                string cv;
                cout<<"Nhap cong viec: "; cin>>cv;
                ql.themmoi(new Nhanvien(ten, t , gt ,cv));
            }

        }
    else if(choice ==2 ){
        string ten;
        cout<<"Nhap ten can tim: "; cin.ignore(); getline(cin,ten);
        ql.timkiem(ten);
    }
    else if(choice ==3){
        ql.hienthi();
    }

    }
    cout<<"Chuong trinh ket thuc!"<<endl;
    return 0;
}