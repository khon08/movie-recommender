#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

class Movie {
private:
    int id;
    string title;
    string genre;
    float rating;

public:
    Movie();
    Movie(int id, string title, string genre, float rating);

    int getId() const;
    string getTitle() const;
    string getGenre() const;
    float getRating() const;

    void setTitle(string title);
    void setGenre(string genre);
    void setRating(float rating);

    bool operator==(const Movie& other) const;
    bool operator<(const Movie& other) const;

    friend ostream& operator<<(ostream& os, const Movie& movie);
};

#endif