#include <iostream>
//#include <numbers>
#include <cmath>

int main()
{
	int height { 74};
//    std::cout<< "the height vriable occupies "<< sizeof height << "bytes."<<std::endl;
//    std::cout<<" Type  \"long long\" occupies "<< sizeof( long long) << "bytes" << std::endl;
//    std::cout<< "The result of the expression height * heighth/2 occupies "
//            << sizeof(height * height/2) << "bytes." << std::endl;
    // increment/decrement operation are  execute before any onther operation
//    std::cout<< ++height + 5<<std::endl; 
//    std::cout<< --height +6 <<std::endl;
    //postfix increment/decrement execute after value is used in context
    
//    int count{5}, total{};
//    std::cout<<"Count before anything:"<< count<< std::endl;
//    std::cout<<"count++ +6: "<< count++ +6<<std::endl;
//    std::cout<<"count after: " <<count<<std::endl;
 
//    std::cout<<std::numbers::pi<<std::endl;

//        double angle {1.5};
//        std::cout<<std::cos(angle)<<std::endl;
    
    double a{1.5},b{},c{};
    double result {a/b};
    std::cout << a <<"/"<<b<<"="<<result<< std::endl;
    std::cout << result << "+" <<a<< "="<< result +a<<std::endl;
    result = b/c;
    std::cout << b<< "/"<<c<<"=" << result<<std::endl;
	return 0;
}
