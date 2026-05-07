#ifndef RATING_H
#define RATING_H

class Rating {
private:
    int userId;
    int movieId;
    int score;

public:
    Rating(int userId, int movieId, int score)
        : userId(userId), movieId(movieId), score(score) {}

    int getUserId() const { return userId; }
    int getMovieId() const { return movieId; }
    int getScore() const { return score; }
};

#endif