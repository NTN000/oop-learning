// cspell:disable
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Superhero{
   private:
        string name,weapon,color;
    public:
        Superhero(string name, string weapon, string color){
             this->name=name;
             this->weapon=weapon;
             this->color=color;
        }
    void display(){
        cout<<"Name:"<< name <<"| Weapon:"<< weapon <<"| Color:"<< color <<endl;
    }
    string getName() const{return name;}
    string getWeapon() const{return weapon;}
    string getColor() const{ return color; }

    void setName(string  name){this->name = name;};
    void setWeapon(string  weapon){ this->weapon = weapon;};
    void setColor(string  color){this->color = color;}; 
};
 
int main(){
   vector<Superhero> danh_sach_sn;
int choice;
string name,weapon,color;
    while (true) {
        cout << "\n--- SUPERHERO SYSTEM ---" << endl;
        cout << "1. Create a Hero" << endl;
        cout << "2. Show the all of list" << endl;
        cout << "3. Exit!"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout<<"Enter name:"; cin>>name;
            cout<<"Enter weapon:" ; cin>>weapon;
            cout<<"Enter color:"; cin>>color;
            

            Superhero tempsHero(name, weapon,color);
            danh_sach_sn.push_back( tempsHero);
            cout<<(20,"=");
            cout << "Hero created!" << endl;
            
        } 
         else if(choice ==2){
            cout << string(30, '=') << endl;
            cout<<"Display all of the list of Heros:\n"<<endl;
            for(int i=0; i<danh_sach_sn.size(); i++){
                danh_sach_sn[i].display();
    
        } }
        else if(choice == 3){
            cout << string(30, '=') << endl;
            cout << "Exiting... Goodbye!" << endl;
            break; // This STOPS the infinite loop
    
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
   
}