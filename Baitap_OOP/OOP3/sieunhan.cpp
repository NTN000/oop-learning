// cspell:disable
#include<iostream>
#include<string>
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
    Superhero SphrA(  "A" ,  "sword",  "red");
    Superhero SphrB("B" , "Gun" , "Green");
    cout<<"SuperHero A:"<<endl;
    SphrA.display();
    cout<< string(15, '=')<<endl;
    cout<<"SuperHero B:"<<endl;
    SphrB.display();
    return 0;
}