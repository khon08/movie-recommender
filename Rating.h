#ifndef RATING_H
#define RATING_H

#include <iostream>

using namespace std;

class Rating {
private:
    int userId;
    int movieId;
    float score;

public:
    Rating();
    Rating(int userId, int movieId, float score);

    int getUserId() const;
    int getMovieId() const;
    float getScore() const;

    void setScore(float score);

    friend ostream& operator<<(ostream& os, const Rating& rating);
};

#endif