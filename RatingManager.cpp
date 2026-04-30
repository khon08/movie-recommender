#include "RatingManager.h"
#include <iostream>
using namespace std;

void RatingManager::addRating(const Rating& rating) {
    ratings.push_back(rating);
}

void RatingManager::printAll() const {
    for (const auto& r : ratings)
        cout << r << endl;
}

void RatingManager::printByMovie(int movieId) const {
    for (const auto& r : ratings)
        if (r.getMovieId() == movieId)
            cout << r << endl;
}

float RatingManager::getAverage(int movieId) const {
    float sum = 0; int count = 0;
    for (const auto& r : ratings)
        if (r.getMovieId() == movieId) {
            sum += r.getScore();
            count++;
        }
    return count > 0 ? sum / count : 0;
}

void RatingManager::loadFromFile(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Error: " << filename << " 열 수 없습니다" << endl;
        return;
    }
    string line;
    getline(f, line);
    while (getline(f, line)) {
        stringstream ss(line);
        string t;
        getline(ss,t,','); int uid = stoi(t);
        getline(ss,t,','); int mid = stoi(t);
        getline(ss,t,','); float score = stof(t);
        ratings.push_back(Rating(uid, mid, score));
    }
    f.close();
    cout << filename << " 로드 완료: " << ratings.size() << "건" << endl;
}

void RatingManager::saveToFile(const string& filename) const {
    ofstream f(filename);
    if (!f.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    f << "userId,movieId,score" << endl;
    for (const auto& r : ratings)
        f << r.getUserId() << "," << r.getMovieId() << ","
          << r.getScore() << endl;
    f.close();
    cout << filename << " 저장 완료: " << ratings.size() << "건" << endl;
}
