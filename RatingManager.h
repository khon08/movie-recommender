#ifndef RATINGMANAGER_H
#define RATINGMANAGER_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Rating.h"
#include "BaseManager.h"
using namespace std;

class RatingManager : public BaseManager {
private:
    vector<Rating> ratings;
public:
    void addRating(const Rating& rating);
    void printAll() const;
    void printByMovie(int movieId) const;
    float getAverage(int movieId) const;
    vector<Rating> getByUser(int userId) const;
    vector<int> getAllUserIds() const;
    void loadFromFile(const string& filename) override;
    void saveToFile(const string& filename) const override;
    int size() const override { return ratings.size(); }
};
#endif
