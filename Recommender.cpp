#include "Recommender.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;

int Recommender::Similaritycalculate(const vector<Rating>& ratingsA,
                                      const vector<Rating>& ratingsB) {
    int common = 0;
    int diff = 0;
    for (const auto& a : ratingsA) {
        for (const auto& b : ratingsB) {
            if (a.getMovieId() == b.getMovieId()) {
                common++;
                diff += abs((int)a.getScore() - (int)b.getScore());
            }
        }
    }
    if (common == 0) return -100;
    return common * 10 - diff;
}

vector<int> Recommender::recommend(int userId, int K, int N) {
    vector<Rating> myRatings = ratingManager.getByUser(userId);
    if (myRatings.empty()) return {};

    vector<pair<int,int>> similarities;
    vector<int> allUsers = ratingManager.getAllUserIds();
    for (int uid : allUsers) {
        if (uid == userId) continue;
        vector<Rating> otherRatings = ratingManager.getByUser(uid);
        int sim = Similaritycalculate(myRatings, otherRatings);
        similarities.push_back({uid, sim});
    }

    sort(similarities.begin(), similarities.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second > b.second;
         });
    int k = min(K, (int)similarities.size());

    set<int> myMovieIds;
    for (const auto& r : myRatings)
        myMovieIds.insert(r.getMovieId());

    map<int,int> movieScores;
    for (int i = 0; i < k; i++) {
        int uid = similarities[i].first;
        vector<Rating> otherRatings = ratingManager.getByUser(uid);
        for (const auto& r : otherRatings) {
            if (myMovieIds.find(r.getMovieId()) == myMovieIds.end()) {
                movieScores[r.getMovieId()] += (int)r.getScore();
            }
        }
    }

    vector<pair<int,int>> sorted(movieScores.begin(), movieScores.end());
    sort(sorted.begin(), sorted.end(),
         [](const pair<int,int>& a, const pair<int,int>& b) {
             return a.second > b.second;
         });

    vector<int> result;
    int n = min(N, (int)sorted.size());
    for (int i = 0; i < n; i++)
        result.push_back(sorted[i].first);
    return result;
}

void Recommender::printRecommendations(int userId, int K, int N) {
    vector<int> result = recommend(userId, K, N);
    if (result.empty()) {
        cout << "No recommendations available." << endl;
        return;
    }
    cout << "\n=== Recommended Movies for User " << userId << " ===" << endl;
    for (int i = 0; i < (int)result.size(); i++) {
        Movie* m = movieManager.findById(result[i]);
        if (m)
            cout << i+1 << ". " << m->getTitle()
                 << " [" << m->getGenre() << "]"
                 << " Rating: " << m->getRating() << endl;
        else
            cout << i+1 << ". Movie ID: " << result[i] << endl;
    }
}