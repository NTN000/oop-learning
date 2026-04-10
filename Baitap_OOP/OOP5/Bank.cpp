// cspell:disable
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;

/// class
class Bank{
    private:
        string ownerName;
        string bankName;
        string Bank_Acc_Number;
        long double  Ballance;
        ///Constructor
    public:
        Bank( string ownerName , string bankName, string Bank_Acc_Number, long double Ballance){
            this->ownerName=ownerName;
            this->bankName=bankName;
            this->Bank_Acc_Number=Bank_Acc_Number;
            this->Ballance=Ballance;
        }
    /// Set and Get
    string getownerName() const{return ownerName;}
    string getbankName() const{return bankName;}
    string getBank_Acc_Number() const{return Bank_Acc_Number;}
    long double getBallance()const{return Ballance;}

    void setownerName(string name){this->ownerName = ownerName;}
    void setbankName(string bankName){this->bankName = bankName;}
    void setBank_Acc_Number(string Bank_Acc_Number){this->Bank_Acc_Number = Bank_Acc_Number;}
    void setBallance(long double Ballance){this->Ballance = Ballance;}

///Method
    /// void display:
    void display(){
        cout<<"OwnerName: "<<ownerName<<"|"
        "BankName: "<<bankName<<"|"
        "Bank_Acc_Number: "<<Bank_Acc_Number<<"|"
        "Balance: "<<Ballance<<endl;
    }
    void Deposit(){
        cout<<"The Balance now: "<<Ballance<<endl;
        long double Cash;
        cout<<"Enter the number of cash: "; cin>>Cash;
            Ballance +=Cash;
            cout<<"The Balance after deposit: "<<Ballance<<endl;}
       
    void Withdraw(){
           cout<<"The Balance now: "<<Ballance<<endl;
        long double Cash;
        cout<<"Enter the number of cash: "; cin>>Cash;
            if(Cash>Ballance){
           cout<<"The Cash is bigger than ur Ballance! Pls Enter again!";
           return;
        }
            else{Ballance -=Cash;
            cout<<"The Balance after withdraw: "<<Ballance<<endl;}
    
};};
/// Intmain
    int main(){
        string ownerName;
        string bankName;
        string Bank_Acc_Number;
        long double  Ballance;
            vector<Bank>The_list_of_bank;
        int choice;
         while(true){
            cout<<"===== Welcome to the Bank =====\n";
            cout<<"Options:\n";
            cout<<"0. Creat BankAccout\n";
            cout<<"1. Display all of the BankAccount\n";
            cout<<"2. Deposit\n";
            cout<<"3. Withdraw\n";
            cout<<"4. End\n";
            cout<<"Enter choice: \n"; cin>>choice;


            if(choice ==4){
                cout<<"END! SEE YA!!!"<<endl;
                break;
            }
            if(choice == 0){
                cout<<"Creat BankAccount: \n";
                cout<<"OwnerName: \n"; cin>>ownerName;
                cout<<"BankName: \n"; cin>>bankName;
                cout<<"Bank_Acc_Number: \n";cin>>Bank_Acc_Number;
                cout<<"Balance: \n";cin>>Ballance;

                Bank BankAccount(ownerName , bankName, Bank_Acc_Number,  Ballance  );
                The_list_of_bank.push_back(BankAccount);
                cout<<"BankAccout Created!";
                cout<<(10,"=");
                cout<<"OwnerName: \n"; 
                    "BankName: \n"; 
                    "Bank_Acc_Number: \n";
                    "Balance: \n";
            }
            if(choice == 1){
                if(The_list_of_bank.empty()){
                    cout << "No accounts found! Please create one first.\n";
                }
                else{
                cout<<"Display all of the BankAccount:\n ";
                for(int i=0; i<The_list_of_bank.size();i++){
                    The_list_of_bank[i].display();
                }}}
                // LOGIC FOR DEPOSIT (Choice 2) AND WITHDRAW (Choice 3)
        if (choice == 2 || choice == 3) {
            if (The_list_of_bank.empty()) {
                cout << "No accounts found! Create one first.\n";
            } else {
                string searchAcc;
                cout << "Enter Account Number to find: "; cin >> searchAcc;

                int foundIndex = -1;
                // Search loop
                for (int i = 0; i < The_list_of_bank.size(); i++) {
                    if (The_list_of_bank[i].getBank_Acc_Number() == searchAcc) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    if (choice == 2) The_list_of_bank[foundIndex].Deposit();
                    else The_list_of_bank[foundIndex].Withdraw();
                } else {
                    cout << "Account not found!\n";
                }
            }
        }
    }
    return 0;
}
            
           