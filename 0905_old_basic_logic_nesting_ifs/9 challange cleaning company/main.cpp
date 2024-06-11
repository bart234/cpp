#include <iostream>

int main()
{
    /* literal const -> x=12 lub name="Frank"
 * w ten sposob sa zapisane \n - new line
 * standad -> const double pi{3.1415};*/
	
    const double priceSmallRoom {10};
    const double priceBigRoom {20};
    const double tax {0.036};
    const double dayvalidate {30.2};
    int smallRooms{};
    int bigRooms{};
    double tempSmall{};
    double tempBig{};
    std::cout<<"Welcome in my room cleaning"<<std::endl;
    std::cout<<"\n\nWe cleaning small and big rooms"<<std::endl;
    std::cout<<"Please put number of:" <<std::endl;
    std::cout<<"\nsmall rooms to clean:";
    std::cin>>smallRooms;
    std::cout<<"big rooms to clean:";
    std::cin>>bigRooms;
    tempSmall=priceSmallRoom*smallRooms;
    tempBig=priceBigRoom*bigRooms;
    std::cout<<"Our wage for small room is: "<<priceSmallRoom<<" and for big room: "<<priceBigRoom<<std::endl;
    std::cout<<"Cost for all small rooms is: "<<tempSmall<<std::endl;
    std::cout<<"Cost for all big rooms is: "<<tempBig<<std::endl;
    std::cout<<"Tax for small rooms is: "<<tempSmall*tax<<" and tax for big room is:"<<tempBig*tax<<std::endl;
    std::cout<<"All cost are:"<<tempSmall+ tempSmall*tax+tempBig+tempBig*tax<<std::endl;
    //    std::cout<<"You have "<< roomNumber<<" to clean"<<std::endl;
//    std::cout<<"Our price per room is: "<<pricePerRoom<<std::endl;
//    std::cout<<"All casts are : "<< roomNumber<<" x " <<pricePerRoom<<std::endl;
//    tempSum = roomNumber*pricePerRoom;
//    std::cout<<"That is equal:"<< tempSum<<std::endl;
//    std::cout<<"Tax for that service is: "<< tempSum*tax<<std::endl;
//    std::cout<<"All cost is:" <<(tempSum)+ (tempSum*tax)<<std::endl;
    
    
	return 0;
}
