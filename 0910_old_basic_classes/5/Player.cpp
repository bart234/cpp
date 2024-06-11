#include "Player.h"
 
void Player::get_damage(int damage){
    //int damage {10};
    hp-=damage;
    std::cout<<"You got hit for "<<damage<< " damage."<<std::endl;
        if (hp<0){
            std::cout<<"You are dead."<<std::endl;
        }else{
            std::cout<<hp<<" life left"<<std::endl;
        }
};

void Player::is_dead(){
    if (hp>0){
        std::cout<<"You alive"<<std::endl;
    }else{
        std::cout<<"You are dead"<<std::endl;
    }
}