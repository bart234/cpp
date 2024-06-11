#include "Movies.h"

Movies::Movies(){};

void Movies::addNewMovie_2(std::string name,double rating,int watched)
{
    if(this->movie_counter==0){movie_counter=1;}
    if(is_movie_exist_ptr_2(name)==nullptr)
    {           
        std::shared_ptr<Movie> temp_ptr = std::make_shared<Movie>(name,movie_counter,rating,watched);
        this->vikiMovies_shptr.push_back(temp_ptr);
        ++movie_counter;
    }
};

std::shared_ptr<Movie> Movies::is_movie_exist_ptr_2(std::string movie_name)
{
    if(vikiMovies_shptr.size()==0)
    {
        return nullptr;    
    }
    for(auto el:vikiMovies_shptr)
    {        
        if(el->getName()== movie_name)
            return el;
    }
    return nullptr;
};

void Movies::displayAllMovies_2() const
{
    std::cout<<"All movies:"<<std::endl;
    for(auto const el:vikiMovies_shptr)
    {std::cout<<el->get_m_id()<<" "<<el->getName()<< " "<<el->getRating()<<" "<<el->getWatchedTimes()<<std::endl;}
};

void Movies::incrementWatchedTime_2(std::string name)
{
    //if exist 
    std::shared_ptr<Movie> temp_ptr=nullptr;
    temp_ptr = is_movie_exist_ptr_2(name);

     if (temp_ptr==nullptr)
     {
        std::cout<<"Increment failed: movie: " <<name<<" does not exist."<<std::endl;
     }
     else
     {
        temp_ptr->increment_watched();
     }     
};

/* //old _1 
bool Movies::is_movie_exist(std::string movie_name)
{    
    if(vikiMovies.size()==0)
        return false;
    
    for(auto &el:vikiMovies)
    {
        if(el.getName()== movie_name){
            std::cout<<"Movie: " << movie_name<< " already exist"<<std::endl;
            return true;}
        else{return false;}
    }
}*/

/* //old 2 - version without pointers

Movie* Movies::is_movie_exist_ptr(std::string movie_name)
{
    if(vikiMovies.size()==0)
    {
        return nullptr;    
    }
    for(auto &el:vikiMovies)
    {
        bool a {el.getName()== movie_name};
        if(el.getName()== movie_name)
        {
        return &el;
        }        
    }
    return nullptr;
};

void Movies::addNewMovie(std::string name,double rating,int watched)
{
    if(this->movie_counter==0){movie_counter=1;}
    if(is_movie_exist_ptr(name)==nullptr)
    {           
        vikiMovies.push_back(Movie{name,movie_counter,rating,watched});
        ++movie_counter;
    }
};

void Movies::incrementWatchedTime(std::string name)
{
    //if exist 
    Movie *temp_ptr=nullptr;
    temp_ptr = is_movie_exist_ptr(name);

     if (temp_ptr==nullptr)
     {
        std::cout<<"Increment failed: movie: " <<name<<" does not exist."<<std::endl;
     }
     else
     {
        temp_ptr->increment_watched();
     }     
     temp_ptr=nullptr;
     delete temp_ptr;
};

void Movies::displayAllMovies() const
{
    std::cout<<"All movies:"<<std::endl;
    for(auto const & el:vikiMovies)
    {std::cout<<el.get_m_id()<<" "<<el.getName()<< " "<<el.getRating()<<" "<<el.getWatchedTimes()<<std::endl;}
};
*/