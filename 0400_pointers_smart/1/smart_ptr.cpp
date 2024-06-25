// smart_ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <map>
#include <string>
#include "textureHolder.h"
std::map<std::string, std::unique_ptr<std::string>> mapStrUptrStr{};

std::unique_ptr<std::string > load_str_to_uniqueptr(std::string to_add) {
    std::unique_ptr<std::string > a{ new std::string{ to_add } };    
    return std::move(a);
}

void add_el_to_map(std::string map_key, std::string map_value) {
    std::unique_ptr<std::string > a{ new std::string{ map_value } };
    mapStrUptrStr[map_key] = std::move(a);
}

int main()
{
    const std::string el1{ "el1" };
    //std::cout <<"el1:"<< &el1 << std::endl;
    std::string result1{ "result1" };
    std::string el2{ "el2" };
    //std::cout << "el2:" << &el2 << std::endl;
    std::string result2{ "result2" };

    textureHolder th;
    th.add_el_to_map(el1, result1);
    th.add_el_to_map(el2, result2);

    std::cout <<"szukamy el2: " << th.find_and_return_value("el1") << std::endl;

    //std::map<std::string, std::string> mapStrStr;
    //mapStrStr[el1] = result1;
    //mapStrStr[el2] = result2;

    //for (auto elmapy : mapStrStr) {
    //    std::cout << elmapy.first << " " << elmapy.second << std::endl;
    //}

    //std::unique_ptr<std::string> uniqStrPtr{ new std::string()};    
    //*uniqStrPtr = el1;
    //std::cout <<"uptr 1: " <<*uniqStrPtr<< "  "<< uniqStrPtr.get() << std::endl;

    //std::unique_ptr<std::string> uniqStrPtr2{ new std::string() };
    //uniqStrPtr2 = load_str_to_uniqueptr(el2);
    //std::cout <<"uptr 2: "<< *uniqStrPtr2 << "  " << uniqStrPtr2.get() << std::endl;

    //add_el_to_map(el1, result1);
    //add_el_to_map(el2, result2);

    //for (auto &el : mapStrUptrStr) {
    //    std::cout <<el.first <<": "<< *el.second << std::endl;
    //}


}

