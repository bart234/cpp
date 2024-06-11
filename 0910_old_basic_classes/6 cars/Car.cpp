#include<cstring>
#include "Car.h"


std::string Car::info(){
//        std::string dor_num_str{};
//        return dor_number;
        std::string info_all{};
        if (nazwa == "none"){
            info_all = "There is no model called 'noname'";
            return info_all;
        }else{
            info_all = "My new car is called " + nazwa ;
        }
        
        if (color == "none" ){ 
            
        }else{
            info_all += " and has " + color + " color.";
        }
//        if (color != "none"){
            
//        }
                
        if (dor_number){
            info_all+=+ " It has " + std::to_string(dor_number) + " dorrs.";
        }
        
        if (engine){
            info_all += nazwa + " has engine " + std::to_string(engine) + "KM .";
        }
        return info_all;
//                + "and engine " + engine + ". I can reach " + speed_max + " speed.";
        }
//        
//int speed_up(int up){
//    speed_current +=up;
//    cout<<"speed increase by "<<up<<" to "<<speed_current<<endl;
//    };
//    
//int speed_down(int down){
//    if ((speed_current -=down) <0){
//        speed_current =0;
//        cout<<"You just stopped"<<endl;
//    }else{
//        //speed_current -=down;
//        cout<<"You slowed down by "<<down<<" to "<<speed_current<<endl;};
//    };
