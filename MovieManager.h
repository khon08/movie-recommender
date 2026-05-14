#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Movie.h"
#include "BaseManager.h"
using namespace std;

class MovieManager : public BaseManager {
private:
    vector<Movie> movies;
public:
    void addMovie(const Movie& movie);
    void printAll() const;
    Movie* findByTitle(const string& title);
    void sortByRating();
    void loadFromFile(const string& filename) override;
    void saveToFile(const string& filename) const override;
    int size() const override { return movies.size(); }
};
#endif
