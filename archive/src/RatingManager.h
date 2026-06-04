#ifndef RATING_MANAGER_H
#define RATING_MANAGER_H

#include <vector>
#include <string>
#include "Rating.h"

class RatingManager {
private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& rating);
    void printAll() const;
    
    // 특정 유저의 평점 목록 반환
    std::vector<Rating> findByUser(int userId) const;
    
    // 모든 유저 ID 반환
    std::vector<int> getAllUserIds() const;
    
    // 파일 I/O
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif