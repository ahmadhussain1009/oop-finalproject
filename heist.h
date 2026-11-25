#ifndef heist_H
#define heist_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

using namespace std;

const int TOTAL_CHARACTERS = 9;
const int TOTAL_LOCATIONS = 7;
const int TOTAL_SUSPECTS = 7;
const int WORD1_LEN = 7;
const int WORD2_LEN = 8;
const int MAX_TURNS = 16;

class GameException : public exception {
private:
    string errorMessage;
public:
    GameException(const string& msg);
    virtual const char* what() const noexcept override;
};

class Entity {
protected:
    string name;
    string description;
    bool inspected;

public:
    Entity();
    Entity(const string& name, const string& desc);
    virtual ~Entity();

    string getName() const;
    string getDescription() const;
    bool isInspected() const;
    void setInspected(bool status);

    virtual void displayDetails() const = 0;
};

#endif
