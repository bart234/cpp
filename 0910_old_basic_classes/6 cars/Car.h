#ifndef _CAR_
#define _CAR_
#include <string>

class Car{
    private:
        //atrr
        std::string nazwa{"none"};
        std::string color;
        int dor_number{};
        double engine{};
        int speed_max{};
        int speed_current{};
   public:     
        //prototype        
    std::string info();
//    int speed_up(int up);
//    int speed_down(int down);  
  
        //different constructors  
    public:
        Car()
        :nazwa{"none"},color{"none"},dor_number{0}
            {};
        Car(std::string name_in, std::string color_in)
        :nazwa{name_in},color{color_in},dor_number{0}
            {};
            
        Car(std::string name_in, int dor_number_in,double engine_in)
            :nazwa{name_in},color{"none"},dor_number{dor_number_in},engine{engine_in}
            {};            
    };

#endif // _CAR_
