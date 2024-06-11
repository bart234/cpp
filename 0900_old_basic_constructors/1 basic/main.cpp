#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    public:
    //atributes
    std::string name;
    int health;
    int xp;
    
    // metods
    void set_name(std::string put_name){
        name = put_name;
        };
    //constructors
    Player(){};
    Player(std::string name){};
    Player(std::string name,int health,int xp){};
    //~destructor
    ~Player(){};
};


int main(){
    {
        Player bart;
        bart.set_name("Bartek");
        cout<<endl;
    }
    
   
    
    return 0;
    }
    






class Account{
private:
    //atrr
    string name;
    double balance {0.0}; 
    
public:   
    //meth
    //declared in line
    void set_balance(double bal){balance = bal;}
    double get_balance() {return balance;}
    
    //method will be declared outside class
    //prototypes
    void set_name(string n);
    string get_name();
    
    bool deposit(double amount);
    bool withdraw(double amount);
};


//Account outside functions
bool Account::withdraw(double amount){
    if ((balance - amount) >=0){
        balance -= amount;
        return true;}
    else{
        return false;
    }
}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

void Account::set_name(string n){
    name = n;
}

string Account::get_name(){
    return name;
}

