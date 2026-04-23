#include "User.h"

User::User() {
    id = 0;
    name = "";
}

User::User(int id, string name) {
    this->id = id;
    this->name = name;
}

int User::getId() const {
    return id;
}

string User::getName() const {
    return name;
}

void User::setName(string name) {
    this->name = name;
}

ostream& operator<<(ostream& os, const User& user) {
    os << "User ID: " << user.id
       << ", Name: " << user.name;
    return os;
}