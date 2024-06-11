#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    public:
    //atributes
    string name;
    int health;
    int xp;
    
    // metods
    void talk(string text_to_say){cout<< name<< " says: "<< text_to_say<<endl;};
    bool is_dead();
};

class Account{
    public:
    //atrr
    string name {"Account"};
    double balance {0.0};    
    //meth
    bool deposit(double);
    bool withdraw(double);
};

int main(){
    Player frank;
    frank.name = "Bartek";
    frank.health = 100;
    frank.xp = 12;
    frank.talk("Hi there");  
    
    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health =78;
    enemy->xp=16;
    enemy->talk("I will destroy you!");
    
    cout<<"Konczymy"; 
//    Account frank_acc;
//    Account brtk_acc;
//    
//    Player ;
//    Player hero;
//    Player players[] {frank,hero};
//    
//    vector<Player> player_vec{frank};
//    player_vec.push_back(hero);
//    
//    Player *enemy(nullptr);
//    enemy = new Player;    
//    delete enemy;    
    return 0;
    }
    
