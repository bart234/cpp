#include <iostream>
#include <vector>

using namespace std;

//---------function prototypes
char show_menu();
void print_numbers (vector<int> myNumbers);
void add_new_number (vector<int> &myNumbers);
void mean_of_viki_elements (const vector<int> &myNumbers);
void smallest_el_of_viki (const vector<int> & myNumbers);
void largest_el_of_viki (const vector<int> & myNumbers);


//------- functions 
void largest_el_of_viki (const vector<int> & myNumbers){
    int sml{};
    sml=myNumbers[0];
    for (auto el:myNumbers){                    
        if (sml<el){
            sml==el;
            }
        }
    cout<<"biggest number is: "<<sml<<endl;
}
void smallest_el_of_viki (const vector<int> & myNumbers){
    int sml{};
    sml=myNumbers[0];
    for (auto el:myNumbers){                    
        if (sml>el){
            sml=el;
            }
        }
    cout<<"smallest number is: "<<sml<<endl;
}
void mean_of_viki_elements (const vector<int> &myNumbers){
    int s{};
    if(myNumbers.size()==1){
        cout<<"mean of numbers is: "<<myNumbers[0]<<endl;
        }
    else{
        for(auto el:myNumbers){s+=el;cout<<el<<" "<<s<<endl; }
        cout<<"mean of numbers is:"<<s/(myNumbers.size());
        cout<<endl;                
    }
}
void add_new_number (vector<int> &myNumbers){
    cout<<"please put new number: ";
    int temp{};
    cin>>temp;
    myNumbers.push_back(temp);
    cout<<"Number added"<<endl;    
    }
void print_numbers (vector<int> myNumbers){
    if (myNumbers.size() ==0){
        cout<<"[] - the list is empty"<<endl;
    }else{
        cout<<"[";
        for(auto el:myNumbers){
            if (myNumbers.size()==1){
                 cout<<el<<endl;
            }else{
                cout<<el<<" ,";
            }            
        }
        cout<<"]"<<endl;
        
    }
}
char show_menu(){
        char decision {};
        cout<<"welcome in my small calculator"<<endl;
        cout<<endl;
        cout<<"Menu:"<<endl;
        cout<<"P - print a numbers"<<endl;
        cout<<"A - add numbers"<<endl;
        cout<<"M - Display mean of the numbers"<<endl;
        cout<<"S - Display smallest of the numbers"<<endl;
        cout<<"L - Display largest of the numbers"<<endl;
        cout<<"Q - Quit"<<endl;
        cin>>decision;
        cout<<endl;
        return toupper(decision);
}


int main(){
    char decision_sign{};   
    vector <int> myNumbers{};
    do{
        decision_sign = show_menu();

        
        switch (decision_sign){
            case 'P':{
                print_numbers(myNumbers);
                break;
            }                
            case 'A':{
                add_new_number(myNumbers);
                break;
            }            
            case 'M':{
                mean_of_viki_elements(myNumbers);
                break;                
            }            
            case 'S':{
               smallest_el_of_viki(myNumbers);
                break;
            }            
            case 'L':{
                largest_el_of_viki(myNumbers);
                break;
            }            
        }        
        
    }while(!(decision_sign == 'Q'));   
    
    
    
    
    
    
//    vector <int> viki{2};
//    int suma{};
//    
//    if (viki.size()<=1){
//        cout<<"suma: "<<0<<endl;
//    }else{
//    
//        for (int i=0;i<viki.size();++i){
//            for (int a=i+1;a<viki.size();++a){
//                cout<<"i="<<i<<" a="<<a<<" * "<<viki[i]*viki[a];
//                suma+=viki[i]*viki[a];
//                cout<<"suma: "<<suma<<endl;
//            }
//    } 
//   }
    
    
    
//    vector <int> vec{ 1,3,5,15,16,17,18,19,20,21,25,26,27,30,50,55,56,58,100,200,300,400,500,600,700};
//    int div3{0}, div5{0};
//    for (auto val:vec){
//        div3+=(val%3==0)?1:0;
//        div5+=(val%5==0)?1:0;
//        
//        }
//    cout<<"wartosci podzielnych przez 3: "<<div3<<endl;
//    cout<<"wartosci podzielnych przez 5: "<<div5<<endl;
    return 0;
}