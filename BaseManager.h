#ifndef BASEMANAGER_H
#define BASEMANAGER_H
#include <string>
using namespace std;

class BaseManager {
public:
    virtual ~BaseManager() {}
    virtual void loadFromFile(const string& filename) = 0;
    virtual void saveToFile(const string& filename) const = 0;
    virtual int size() const = 0;
};
#endif
