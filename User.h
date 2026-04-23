#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    int id;
    string name;

public:
    User();
    User(int id, string name);

    int getId() const;
    string getName() const;

    void setName(string name);

    friend ostream& operator<<(ostream& os, const User& user);
};

#endif