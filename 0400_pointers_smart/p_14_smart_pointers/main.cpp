#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

vector<int> new_viki{1,2,3,45,6};

//  shared pointers 
int main()
{
	std::shared_ptr<int> p1 {new int{100}};
	cout<<*p1<<endl;
	*p1=234;
	cout<<"Value: "<<*p1<<" use count: "<<p1.use_count()<<endl;
	
	std::shared_ptr<int> p2 {p1};
	std::shared_ptr<int> p3{new int{4}};
	
	cout<<"Value: "<<*p2<<" use count: "<<p2.use_count()<<endl;
	p2.reset();
	cout<<"Value: "<<*p1<<" use count: "<<p1.use_count()<<endl;
	std::vector<std::shared_ptr<int>> v2;
	
	v2.push_back(p1);
	v2.push_back(p3);
	cout<<"llop"<<endl;
	for(const auto &el:v2){cout<<*el<<endl;}
	cout<<"Value: "<<*p1<<" use count: "<<p1.use_count()<<endl;
	
	//make_shared should be use insted of 'new'
	//is more efficient and you can add arguments to constructor
	//std::shared_ptr<int> p3 = std::make_shared<int>(100);
	
	enum class my_enum_1 {abba=8,beta,gamma=7,omega};
	my_enum_1 e1 = my_enum_1::abba;
	cout<<int(e1)<<endl;
	
	
	return 0;	
}




/* //smart unique pointers //
int main()
{
	std::vector<std::vector<std::unique_ptr<Field>>> b2;


    for(int y =1; y<= 8;++y)
    {   
        std::vector<std::unique_ptr<Field>> one_row;
        for(int x =1; x<= 8;++x)
        {  
            std::unique_ptr<Field>f1{new Field{x,y}};
            one_row.push_back(std::move(f1)); 
        }
        b2.push_back(std::move(one_row));  
    }

    for(int y =0; y<= b2.size()-1;++y)
    {
        for(int x =0; x<= b2.at(y).size()-1;++x)
        {
            std::cout<<"x: " <<b2.at(y).at(x)->x<<" y: " <<b2.at(y).at(x)->y<<std::endl;
        }
    }

	
	std::unique_ptr<int> p1 {new int {100}};
	cout<<"adress use get(): "<< p1.get()<<endl;
	cout<<"value: "<< *p1<<endl;
	cout<<"Change value to 200"<<endl;
	*p1 =200;
	cout<<"value: "<< *p1<<endl;
	cout<<"Check if is initialed if(p1)"<<endl;
	//p1.reset(); == //p1=nullptr;
	if(p1){cout<<"im initialized"<<endl;}
	else{cout<<"im not initalized"<<endl;}
	
	
	std::vector<std::unique_ptr <int>> v1;
	std::unique_ptr<int> p2 {new int{200}};
	v1.push_back(std::move(p2));
	
	std::unique_ptr<int> p3 = make_unique<int>(100);
	v1.push_back(std::move(p3));
	//cout<<*(v1[1])<<endl;
	
	//error: use of deleted function :
	//we cannot copy share_ptr, soe we have to loop it
	//trough reference, we get reference to pointer
	//so we have to dereference
	for(const auto &el:v1){cout<<*el<<endl;}
	cout<<v1.size()<<endl;
	for(int i =0 ; i<v1.size();++i){cout<<*(v1[i])<<endl;}
	
	return 0;
}
*/
	