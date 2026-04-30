#ifndef RATINGMANAGER_H
#define RATINGMANAGER_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Rating.h"
using namespace std;

class RatingManager {
private:
    vector<Rating> ratings;
public:
    void addRating(const Rating& rating);
    void printAll() const;
    void printByMovie(int movieId) const;
    float getAverage(int movieId) const;
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename) const;
};
#endif
