#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

#include <vector>
#include <string>
#include "Movie.h"

class MovieManager {
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie& movie);
    void printAll() const;

    // 특정 ID로 영화 찾기
    Movie* findById(int id);

    // 파일 I/O
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif