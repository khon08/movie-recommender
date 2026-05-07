#include "MovieManager.h"
#include <iostream>
#include <algorithm>
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
    getline(f, line); // header skip
    while (getline(f, line)) {
        stringstream ss(line);
        string t;
        getline(ss,t,','); int id = stoi(t);
        getline(ss,t,','); string title = t;
        getline(ss,t,','); string genre = t;
        getline(ss,t,','); float rating = stof(t);
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
