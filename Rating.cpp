#include "Rating.h"

Rating::Rating() {
    userId = 0;
    movieId = 0;
    score = 0.0;
}

Rating::Rating(int userId, int movieId, float score) {
    this->userId = userId;
    this->movieId = movieId;
    this->score = score;
}

int Rating::getUserId() const {
    return userId;
}

int Rating::getMovieId() const {
    return movieId;
}

float Rating::getScore() const {
    return score;
}

void Rating::setScore(float score) {
    this->score = score;
}

ostream& operator<<(ostream& os, const Rating& rating) {
    os << "User ID: " << rating.userId
       << ", Movie ID: " << rating.movieId
       << ", Score: " << rating.score;
    return os;
}