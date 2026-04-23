#include "Movie.h"

Movie::Movie() {
    id = 0;
    title = "";
    genre = "";
    rating = 0.0;
}

Movie::Movie(int id, string title, string genre, float rating) {
    this->id = id;
    this->title = title;
    this->genre = genre;
    this->rating = rating;
}

int Movie::getId() const {
    return id;
}

string Movie::getTitle() const {
    return title;
}

string Movie::getGenre() const {
    return genre;
}

float Movie::getRating() const {
    return rating;
}

void Movie::setTitle(string title) {
    this->title = title;
}

void Movie::setGenre(string genre) {
    this->genre = genre;
}

void Movie::setRating(float rating) {
    this->rating = rating;
}

bool Movie::operator==(const Movie& other) const {
    return title == other.title;
}

bool Movie::operator<(const Movie& other) const {
    return rating < other.rating;
}

ostream& operator<<(ostream& os, const Movie& movie) {
    os << "ID: " << movie.id
       << ", Title: " << movie.title
       << ", Genre: " << movie.genre
       << ", Rating: " << movie.rating;
    return os;
}