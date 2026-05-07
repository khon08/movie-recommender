#include "MovieManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void MovieManager::addMovie(const Movie& movie) {
    movies.push_back(movie);
}

void MovieManager::printAll() const {
    for (const Movie& m : movies) {
        std::cout << "ID: " << m.getId()
                  << " | Title: " << m.getTitle()
                  << " | Genre: " << m.getGenre() << "\n";
    }
}

Movie* MovieManager::findById(int id) {
    for (Movie& m : movies) {
        if (m.getId() == id) {
            return &m;
        }
    }
    return nullptr;
}

void MovieManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "파일을 열 수 없습니다: " << filename << "\n";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        int id;
        std::string title, genre;

        std::getline(ss, token, ','); id = std::stoi(token);
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');

        addMovie(Movie(id, title, genre));
    }
    file.close();
}

void MovieManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "파일을 열 수 없습니다: " << filename << "\n";
        return;
    }
    for (const Movie& m : movies) {
        file << m.getId() << ","
             << m.getTitle() << ","
             << m.getGenre() << "\n";
    }
    file.close();
}