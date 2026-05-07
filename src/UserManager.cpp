#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

void UserManager::printAll() const {
    for (const User& u : users) {
        std::cout << "ID: " << u.getId()
                  << " | Name: " << u.getName() << "\n";
    }
}

User* UserManager::findById(int id) {
    for (User& u : users) {
        if (u.getId() == id) {
            return &u;
        }
    }
    return nullptr;
}

void UserManager::loadFromFile(const std::string& filename) {
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
        std::string name;

        std::getline(ss, token, ','); id = std::stoi(token);
        std::getline(ss, name, ',');

        addUser(User(id, name));
    }
    file.close();
}

void UserManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "파일을 열 수 없습니다: " << filename << "\n";
        return;
    }
    for (const User& u : users) {
        file << u.getId() << ","
             << u.getName() << "\n";
    }
    file.close();
}