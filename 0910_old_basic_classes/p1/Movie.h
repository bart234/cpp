#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "Struct.h"


class Movie
{
    private:

    int m_id;
    std::string name;
    std::vector<SimilarityStruct> viki_of_similarty{};
    double rating;
    int watched_times;

    public:
    Movie(std::string name,int m_id, double rating, int watched);
    Movie(std::string name,int m_id, double rating);
    Movie(std::string name,int m_id);
    ~Movie();

    std::string getName()const;
    double getRating() const;
    int getWatchedTimes() const;
    int get_m_id() const;

    //std::string getMovie();
    void set_rating(int rating);
    void set_watched(int watched_times);
    void set_m_id(int m_id);
    void increment_watched();
    void set_similar_movie(std::string movie_name, similar_by kind_of_similarity);

    //print
    void printSimilarMovies() const;
};

