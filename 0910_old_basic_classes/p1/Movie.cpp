#include "Movie.h"

//constrs
Movie::Movie(std::string name, int m_id, double rating, int watched_times):
    name{name},rating{rating},watched_times{watched_times},m_id{m_id}{}
Movie::Movie(std::string name, int m_id, double rating):Movie{name,m_id,rating,0}{};
Movie::Movie(std::string name, int m_id):Movie{name,m_id,0,0}{};
Movie::~Movie(){};//std::cout<<"Movie destructor for: " << this->name<<std::endl;}
//getters
std::string Movie::getName() const{return name;}
double Movie::getRating()const {return rating;}
int Movie::getWatchedTimes()const {return watched_times;}
int Movie::get_m_id() const {return m_id;};
//setters
//std::string Movie::getMovie(){return "Name:"; }
void Movie::set_rating(int rating){this->rating = rating;}
void Movie::set_watched(int watched_times){this->watched_times=watched_times;}
void Movie::set_m_id(int m_id){this->m_id=m_id;}
void Movie::increment_watched(){++watched_times;}
//print
void Movie::printSimilarMovies()const{};