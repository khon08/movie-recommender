#include "UserManager.h"
#include <iostream>
using namespace std;

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

void UserManager::printAll() const {
    for (const auto& u : users)
        cout << u << endl;
}

User* UserManager::findById(int id) {
    for (auto& u : users)
        if (u.getId() == id)
            return &u;
    return nullptr;
}

void UserManager::loadFromFile(const string& filename) {
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
        getline(ss,t,','); int id = stoi(t);
        getline(ss,t,','); string name = t;
        users.push_back(User(id, name));
    }
    f.close();
    cout << filename << " 로드 완료: " << users.size() << "건" << endl;
}

void UserManager::saveToFile(const string& filename) const {
    ofstream f(filename);
    if (!f.is_open()) {
        cerr << "Error: " << filename << " 저장 실패" << endl;
        return;
    }
    f << "id,name" << endl;
    for (const auto& u : users)
        f << u.getId() << "," << u.getName() << endl;
    f.close();
    cout << filename << " 저장 완료: " << users.size() << "건" << endl;
}
