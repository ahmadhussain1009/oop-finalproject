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
