#include "heist.h"

GameException::GameException(const string& msg) : errorMessage(msg) {}

const char* GameException::what() const noexcept {
    return errorMessage.c_str();
}

Entity::Entity() : name("Unknown"), description("None"), inspected(false) {}

Entity::Entity(const string& name, const string& desc)
    : name(name), description(desc), inspected(false) {}

Entity::~Entity() {}

string Entity::getName() const { return name; }
string Entity::getDescription() const { return description; }
bool Entity::isInspected() const { return inspected; }
void Entity::setInspected(bool status) { inspected = status; }

Location::Location() : Entity(), hiddenLetter('_'), letterPosition(0) {}

Location::Location(const string& name, const string& desc)
    : Entity(name, desc), hiddenLetter('_'), letterPosition(0) {}

void Location::setClue(char letter, int pos) {
    hiddenLetter = letter;
    letterPosition = pos;
}

char Location::getHiddenLetter() const { return hiddenLetter; }
int Location::getLetterPosition() const { return letterPosition; }

void Location::displayDetails() const {
    cout << "[Location] " << name << " - " << description;
    if (inspected) {
        cout << " (Searched: Letter '" << hiddenLetter << "' at Pos " << letterPosition << ")";
    }
    cout << endl;
}

Suspect::Suspect() : Entity(), alibi("None"), hiddenLetter('_'), letterPosition(0), isCulprit(false) {}

Suspect::Suspect(const string& name, const string& desc, const string& alibi)
    : Entity(name, desc), alibi(alibi), hiddenLetter('_'), letterPosition(0), isCulprit(false) {}

void Suspect::setClue(char letter, int pos) {
    hiddenLetter = letter;
    letterPosition = pos;
}

void Suspect::setCulprit(bool culprit) { isCulprit = culprit; }
bool Suspect::getCulprit() const { return isCulprit; }
string Suspect::getAlibi() const { return alibi; }
char Suspect::getHiddenLetter() const { return hiddenLetter; }
int Suspect::getLetterPosition() const { return letterPosition; }

void Suspect::displayDetails() const {
    cout << "[Suspect] " << name << " (" << description << ")";
    if (inspected) {
        cout << " - Alibi: \"" << alibi << "\" | Clue: '" << hiddenLetter << "' at Pos " << letterPosition;
    }
    cout << endl;
}
