#include <iostream>
#include "Movies.h"

//have to wait - todo: overload operators: print << , 
//usless-in this case - todo: raw pointer from increament watchlist switch to unique_ptr
//usless-in this case - todo: add copy constructor
//done: switch vikiMovies vector<Movies> in to vikiMovies vector<sharepointer<movies>>
//done: commented: usless :todo: add destructor and comments to see then it happen
//todo: add to movie vector similar movies with vector <ref to movie, similar by>
//todo: add to movie field similar by:
//todo: add enum class with similar by
//todo: add menu class with operation on movies

int main()
{
    Movies m_lib{};
    /*
    //m_lib.addNewMovie("Shrek 1",9,23);
    m_lib.addNewMovie("Lot",0.2,1);
    m_lib.addNewMovie("Shrek 1",9,23);
    m_lib.addNewMovie("Apollo",4,1);
    m_lib.addNewMovie("Lot",4,1);
    m_lib.incrementWatchedTime("Apol2lo");
    */
    m_lib.addNewMovie_2("Lot",0.2,1);
    m_lib.addNewMovie_2("Lot",5,1);
    m_lib.addNewMovie_2("Shrek 1",9,23);
    m_lib.addNewMovie_2("Apollo",4,1);
    m_lib.addNewMovie_2("Lot",4,1);
    m_lib.incrementWatchedTime_2("Apol2lo");
    m_lib.incrementWatchedTime_2("Apollo");
    m_lib.displayAllMovies_2();
    return 0;
}