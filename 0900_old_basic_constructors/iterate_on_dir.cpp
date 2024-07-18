#include <iostream>
#include <filesystem>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <source_location>


using namespace std;

namespace all_ctors
{   
    struct Mean_
    {
        friend std::ostream& operator<<(std::ostream& os, const Mean_& a);

        Mean_() = default;
        Mean_(Mean_&& a) noexcept
            {   
                sum =a.sum;
                count=a.count;
                //a.sum=0;
                //a.count=-1;
                std::cout<<"Move op"<<std::endl;
            }
        Mean_& operator=(Mean_&& a) noexcept
        {
            sum=a.sum;
            count=a.count;
            std::cout<<"Copy op"<<std::endl;
            return *this;
        }

        Mean_(const Mean_ & a) noexcept: sum{a.sum},count{a.count}
        {
            std::cout<<"Constr from assgin"<<std::endl;
        };

        public:
        double result{};
        double sum{};
        int count{};
        

        public:
        double wynik(){return sum/count;}
        void operator()(const double& val)
        {            
            this->sum +=val;
            ++this->count;
            std::cout<<"() op with val: "<< val<<std::endl;
        }
    };
/*
    std::ostream& operator<<(std::ostream& os, const Mean& a)
    {
        double m{std::nan("")};
        if(a.count >0)
        {
            m = a.sum / a.count;
        }
        os << m;
        return os;
    }
*/
    void make_ctor_on_structure()
    {
        Mean_ calc_mean;
        std::vector v1{1.0, 2.5, 4.0, 5.5};
        std::for_each(v1.begin(),v1.end(), std::ref(calc_mean));
        //std::for_each(v1.begin(),v1.end(), calc_mean); --it doesnt work, during copying it lost saved value
        std::cout<<"done"<<std::endl;
        std::cout<<"This mean value is: "<< calc_mean.sum<<'\n';

        
    }
}



int main ()
{
    all_ctors::make_ctor_on_structure();
    
    return 0;
}