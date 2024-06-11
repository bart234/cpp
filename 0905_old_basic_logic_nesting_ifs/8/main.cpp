#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter wind speed to get info what sould you wear"<<endl;
    int coat{23}, umbrella{10}, dontGoOut{50}, rain{0};
    double wind{0.0};
    cin>>wind;
    cout<<"Now enter info about rain, is raining? (y=1,n=0)"<<endl;
    int answer{0};
    cin>>answer;
    if (answer == 0){
        rain = 0;
    }else{
        cout<<"How big is a rain: "<<endl;
        cout<<"1 - small"<<endl;
        cout<<"2 - mid"<<endl;
        cout<<"3- heavy"<<endl;
        cout<<"4 - pouring"<<endl;
        cin>>rain;
    }
    cout<<"So let check: "<<endl;
    if (wind>dontGoOut){
        cout<<"just dont go out";
    }else if (wind>coat){
        cout<<"just take a coat for wind";
    }else if (wind>umbrella){
        cout<<"just take umbrella for a wind";
    }else{
        cout<<"or do something else";
    }
    
    cout<<endl;
    return 0;
}