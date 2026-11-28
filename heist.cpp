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
ClueNotebook::ClueNotebook() : cluesFoundCount(0) {
    for (int i = 0; i < WORD1_LEN; i++) discoveredWord1[i] = '_';
    for (int i = 0; i < WORD2_LEN; i++) discoveredWord2[i] = '_';
}

void ClueNotebook::recordLocationClue(char letter, int position) {
    if (position < 1 || position > WORD1_LEN) {
        throw GameException("Invalid Word 1 letter position encountered!");
    }
    if (discoveredWord1[position - 1] == '_') {
        discoveredWord1[position - 1] = letter;
        cluesFoundCount++;
    }
}

void ClueNotebook::recordCharacterClue(char letter, int position) {
    if (position < 1 || position > WORD2_LEN) {
        throw GameException("Invalid Word 2 letter position encountered!");
    }
    if (discoveredWord2[position - 1] == '_') {
        discoveredWord2[position - 1] = letter;
        cluesFoundCount++;
    }
}

void ClueNotebook::displayNotebook() const {
    cout << "\n================ DETECTIVE CLUE NOTEBOOK ================\n";
    cout << "Word 1 (Locations - 7 Letters):  ";
    for (int i = 0; i < WORD1_LEN; i++) {
        cout << discoveredWord1[i] << " ";
    }
    cout << "\nPositions:                       1 2 3 4 5 6 7\n\n";

    cout << "Word 2 (Characters - 8 Letters): ";
    for (int i = 0; i < WORD2_LEN; i++) {
        cout << discoveredWord2[i] << " ";
    }
    cout << "\nPositions:                       1 2 3 4 5 6 7 8\n";
    cout << "Total Clues Collected: " << cluesFoundCount << " / 15\n";
    cout << "=========================================================\n";
}

int ClueNotebook::getCluesFoundCount() const {
    return cluesFoundCount;
}
