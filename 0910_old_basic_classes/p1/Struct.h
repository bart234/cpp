#pragma once
#include <memory>

enum class similar_by{Plot,Genre,Type,Actors};

class Movie;    

struct SimilarityStruct
{
    std::shared_ptr<Movie> movie;
    similar_by kind_of_similarity;
};