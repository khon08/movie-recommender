#ifndef RECOMMENDER_H
#define RECOMMENDER_H
#include <vector>
#include "Rating.h"
#include "MovieManager.h"
#include "RatingManager.h"
using namespace std;

class Recommender {
private:
    MovieManager& movieManager;
    RatingManager& ratingManager;
public:
    Recommender(MovieManager& mm, RatingManager& rm)
        : movieManager(mm), ratingManager(rm) {}

    int Similaritycalculate(const vector<Rating>& ratingsA,
                            const vector<Rating>& ratingsB);

    vector<int> recommend(int userId, int K, int N);
    void printRecommendations(int userId, int K, int N);
};
#endif