#include "RatingManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void RatingManager::addRating(const Rating& rating) {
    ratings.push_back(rating);
}

void RatingManager::printAll() const {
    for (const Rating& r : ratings) {
        std::cout << "User " << r.getUserId()
                  << " | Movie " << r.getMovieId()
                  << " | Score " << r.getScore() << "\n";
    }
}

std::vector<Rating> RatingManager::findByUser(int userId) const {
    std::vector<Rating> result;
    for (const Rating& r : ratings) {
        if (r.getUserId() == userId) {
            result.push_back(r);
        }
    }
    return result;
}

std::vector<int> RatingManager::getAllUserIds() const {
    std::vector<int> ids;
    for (const Rating& r : ratings) {
        bool found = false;
        for (int id : ids) {
            if (id == r.getUserId()) {
                found = true;
                break;
            }
        }
        if (!found) {
            ids.push_back(r.getUserId());
        }
    }
    return ids;
}

void RatingManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "파일을 열 수 없습니다: " << filename << "\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        int userId, movieId, score;

        std::getline(ss, token, ','); userId = std::stoi(token);
        std::getline(ss, token, ','); movieId = std::stoi(token);
        std::getline(ss, token, ','); score = std::stoi(token);

        addRating(Rating(userId, movieId, score));
    }
    file.close();
}

void RatingManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "파일을 열 수 없습니다: " << filename << "\n";
        return;
    }
    for (const Rating& r : ratings) {
        file << r.getUserId() << ","
             << r.getMovieId() << ","
             << r.getScore() << "\n";
    }
    file.close();
}