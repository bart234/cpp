#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Movie.h"

class Movies
{
    private:
    int movie_counter{0};
    std::vector<Movie> vikiMovies{};    
    Movie* is_movie_exist_ptr(std::string movie_name);    //todo: stind upper vs lower? 
    public:
    void addNewMovie(std::string name,double rating =0,int watched=0);
    void incrementWatchedTime(std::string name);
    void displayAllMovies()const ;
    Movies();

    private:
    std::vector<std::shared_ptr <Movie>> vikiMovies_shptr{};
    std::shared_ptr<Movie> is_movie_exist_ptr_2(std::string movie_name);
    public:
    void addNewMovie_2(std::string name,double rating =0,int watched=0);
    void incrementWatchedTime_2(std::string name);
    void displayAllMovies_2()const;
};

//bool is_movie_exist(std::string movie_name);    //todo: stind upper vs lower? 
