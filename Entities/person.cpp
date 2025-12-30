#include "person.h"
#include <sstream>
#include <algorithm>

Person::Person(const std::string& firstName, const std::string& lastName, 
               const std::string& middleName, int age, const std::string& id,
               bool hasChildren, bool isPensioner, bool isDisabled)
    : firstName(firstName), lastName(lastName), middleName(middleName),
      age(age), id(id), hasChildren(hasChildren),
      isPensioner(isPensioner), isDisabled(isDisabled) {}

std::string Person::getFullName() const {
    return lastName + " " + firstName + " " + middleName;
}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

std::string Person::getMiddleName() const {
    return middleName;
}

int Person::getAge() const {
    return age;
}

std::string Person::getId() const {
    return id;
}

bool Person::getHasChildren() const {
    return hasChildren;
}

bool Person::getIsPensioner() const {
    return isPensioner;
}

bool Person::getIsDisabled() const {
    return isDisabled;
}

void Person::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Person::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Person::setMiddleName(const std::string& middleName) {
    this->middleName = middleName;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setHasChildren(bool hasChildren) {
    this->hasChildren = hasChildren;
}

void Person::setIsPensioner(bool isPensioner) {
    this->isPensioner = isPensioner;
}

void Person::setIsDisabled(bool isDisabled) {
    this->isDisabled = isDisabled;
}

std::vector<std::shared_ptr<Person>> Person::findByFullName(
    const std::vector<std::shared_ptr<Person>>& people,
    const std::string& fullName) {
    
    std::vector<std::shared_ptr<Person>> result;
    for (const auto& person : people) {
        if (person->getFullName().find(fullName) != std::string::npos) {
            result.push_back(person);
        }
    }
    return result;
}
