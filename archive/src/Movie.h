#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    int id;
    std::string title;
    std::string genre;

public:
    Movie(int id, const std::string& title, const std::string& genre)
        : id(id), title(title), genre(genre) {}

    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getGenre() const { return genre; }
};

#endif