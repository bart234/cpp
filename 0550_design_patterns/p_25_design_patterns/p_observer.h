#ifndef SOURCES_H
#define SOURCES_H

#include "sources.h"

namespace p_observer
{
//observer pattern
/*
    something is what we ant to observ
    some obverving object

    object "be observ": 
        -it have list of observers
        - observers can be add or remove
        - object have some value which is value for other eg: some data
        - have function which notify all observers "i have fresh data"
            - it can send that data to all observers
            - or
            - it only inform them - there are new data - download it by yourself from my source
        - it can fetch whole data, it can fetch only new data, it can fetch new data filter by observer - what he need 
    
    object observer (many):
        - it have add itself to subscriber list ("here is my adress, if you get something new, let me know")
        - if notification is send : notification with data 
            -or observer launch script which download data (all data / selected data/ new data)

    main:
        initiate obj to observ 
        initiate kind of subscriber (x3)
        add each subscriber to observerr subscription
        print subscribers value
        add data to obj
        send notification about "data change" 
        (base class: have function to override inform_me and each child will download data from)
        print subscribers data 

*/

class Subscriber
{       
    protected:
    int id;
    int my_value={-1};   

    public: 
    Subscriber(int id_){id=id_;};
    void notifyMy(){this->makeAction();}
    virtual void makeAction()=0;
    //void set_data(int new_value){this->my_value=new_value;};
    void printMe(){cout<<my_value<<endl;};
};

class Nowacka: public Subscriber
{
    public: Nowacka(int id_):Subscriber{id_}{};
    void makeAction(){cout<<"THis is Nowacka action, id: "<<id<<endl;};
};

class PanAntoin:public Subscriber
{
    public: PanAntoin(int id_):Subscriber{id_}{};
    void makeAction(){cout<<"THis is PanAntoni action, id: "<<id<<endl;};
};


class Newspaper
{
    
    int data_ ={0};
    std::vector<Subscriber*> subscriber_list={};

    public:
    void addObserver(Subscriber* sub){subscriber_list.push_back(sub);};
    void removeObserver(Subscriber* sub);
    void notifyAll()
            {
                for(auto el:subscriber_list)
                {
                    //notify? it sending data to observer
                    //el->set_data(this->data_);
                    el->notifyMy();
                }
            }
    void changeData(int new_data){this->data_=new_data;};
    int getData(){return data_;};
    void printAll()
            {
                for(auto el:subscriber_list)
                {
                    //notify? it sending data to observer
                    el->printMe();
                }
            }
};


    void run_me()
    {
        /*
        std::vector<int> a;
        a.push_back(4);

        std::vector<std::string*> b;
        std::string* s = new std::string("abba");
        b.push_back(s);

        std::vector<Subscriber*>c;
        PanAntoin* c1 = new PanAntoin();
        c.push_back(c1);
        */

        
        cout<<"dp observer"<<endl;

        Newspaper nsp{};
        PanAntoin* a1 = new PanAntoin(23);
        Nowacka* a2 = new Nowacka(44);

        nsp.addObserver(a1);
        nsp.addObserver(a2);

        cout<<"Print before"<<endl;
        nsp.printAll();
        cout<<"Change data"<<endl;
        nsp.changeData(3);
        nsp.notifyAll();
        cout<<"Print after"<<endl;
        nsp.printAll();
    }
}

#endif