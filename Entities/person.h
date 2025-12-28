#pragma once
#include <string>
#include <memory>
#include <vector>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    std::string middleName;
    int age;
    std::string id;
    bool hasChildren;
    bool isPensioner;
    bool isDisabled;
    
public:
    Person(const std::string& firstName, const std::string& lastName, 
           const std::string& middleName, int age, const std::string& id,
           bool hasChildren = false, bool isPensioner = false, bool isDisabled = false);
    virtual ~Person() = default;
    
    virtual std::string getInfo() const = 0;
    virtual std::string getType() const = 0;
    
    std::string getFullName() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getMiddleName() const;
    int getAge() const;
    std::string getId() const;
    bool getHasChildren() const;
    bool getIsPensioner() const;
    bool getIsDisabled() const;
    
    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setMiddleName(const std::string& middleName);
    void setAge(int age);
    void setHasChildren(bool hasChildren);
    void setIsPensioner(bool isPensioner);
    void setIsDisabled(bool isDisabled);
    
    static std::vector<std::shared_ptr<Person>> findByFullName(
        const std::vector<std::shared_ptr<Person>>& people,
        const std::string& fullName);
};
