#include "MovieManager.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdexcept>
using namespace std;

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}
void MovieManager::printAll() const {
    for (const auto& m : movies)
        cout << m << endl;
}
Movie* MovieManager::findByTitle(const string& title) {
    for (auto& m : movies)
        if (m.getTitle() == title)
            return &m;
    return nullptr;
}
Movie* MovieManager::findById(int id) {
    for (auto& m : movies)
        if (m.getId() == id)
            return &m;
    return nullptr;
}
void MovieManager::sortByRating() {
    sort(movies.begin(), movies.end());
}
void MovieManager::loadFromFile(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        cerr << "Error: " << filename << " 열 수 없습니다" << endl;
        return;
    }
    string line;
    getline(f, line);
    while (getline(f, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string t;
        getline(ss,t,','); int id = stoi(t);
        getline(ss,t,','); string title = t;
        getline(ss,t,','); string genre = t;
        float rating = 0.0;
        if (getline(ss,t,',')) rating = stof(t);
        movies.push_back(Movie(id, title, genre, rating));
    }
    f.close();
    cout << filename << " 로드 완료: " << movies.size() << "건" << endl;
}
void MovieManager::saveToFile(const string& filename) const {
    ofstream f(filename);
    if (!f.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    f << "id,title,genre,rating" << endl;
    for (const auto& m : movies)
        f << m.getId() << "," << m.getTitle() << ","
          << m.getGenre() << "," << m.getRating() << endl;
    f.close();
    cout << filename << " 저장 완료: " << movies.size() << "건" << endl;
}

// 14-hafta: yangi funksiyalar
vector<Movie> MovieManager::filterByGenre(const string& genre) const {
    vector<Movie> result;
    for (const auto& m : movies)
        if (m.getGenre() == genre)
            result.push_back(m);
    return result;
}

double MovieManager::getAverageRating() const {
    if (movies.empty())
        throw runtime_error("영화 데이터가 없습니다.");
    double sum = accumulate(movies.begin(), movies.end(), 0.0,
        [](double acc, const Movie& m) {
            return acc + m.getRating();
        });
    return sum / movies.size();
}

vector<Movie> MovieManager::getTopN(int n) const {
    auto sorted = movies;
    sort(sorted.begin(), sorted.end(),
        [](const Movie& a, const Movie& b) {
            return a.getRating() > b.getRating();
        });
    if (n > (int)sorted.size()) n = sorted.size();
    return vector<Movie>(sorted.begin(), sorted.begin() + n);
}

map<string, double> MovieManager::getAverageRatingByGenre() const {
    map<string, double> sumByGenre;
    map<string, int> countByGenre;
    for (const auto& m : movies) {
        sumByGenre[m.getGenre()] += m.getRating();
        countByGenre[m.getGenre()]++;
    }
    map<string, double> avgByGenre;
    for (const auto& [genre, sum] : sumByGenre)
        avgByGenre[genre] = sum / countByGenre[genre];
    return avgByGenre;
}
