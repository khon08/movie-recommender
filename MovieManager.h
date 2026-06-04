#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H
#include <vector>
#include <string>
#include <map>
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
    Movie* findById(int id);
    void sortByRating();
    void loadFromFile(const string& filename) override;
    void saveToFile(const string& filename) const override;
    int size() const override { return movies.size(); }
    // 14-hafta: kengaytirilgan funksiyalar
    vector<Movie> filterByGenre(const string& genre) const;
    double getAverageRating() const;
    vector<Movie> getTopN(int n) const;
    map<string, double> getAverageRatingByGenre() const;
};
#endif
