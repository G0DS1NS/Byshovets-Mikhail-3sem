#include "Employee.h"
#include <sstream>
#include <algorithm>

Employee::Employee(const std::string& firstName, const std::string& lastName, 
                   const std::string& middleName, int age, const std::string& id,
                   const std::string& position, double salaryRate,
                   bool hasChildren, bool isPensioner, bool isDisabled,
                   bool onRegularVacation, bool onChildcareLeave)
    : Person(firstName, lastName, middleName, age, id, 
             hasChildren, isPensioner, isDisabled),
      position(position), salaryRate(salaryRate),
      onRegularVacation(onRegularVacation), onChildcareLeave(onChildcareLeave) {}

std::string Employee::getInfo() const {
    std::stringstream ss;
    ss << "Сотрудник: " << getFullName()
       << "\nВозраст: " << age
       << "\nДолжность: " << position
       << "\nСтавка: " << salaryRate
       << "\nID: " << id
       << "\nДети: " << (hasChildren ? "Есть" : "Нет")
       << "\nПенсионер: " << (isPensioner ? "Да" : "Нет")
       << "\nИнвалид: " << (isDisabled ? "Да" : "Нет")
       << "\nОчередной отпуск: " << (onRegularVacation ? "Да" : "Нет")
       << "\nОтпуск по уходу за ребенком: " << (onChildcareLeave ? "Да" : "Нет")
       << "\nПредыдущих мест работы: " << previousJobs.size();
    
    if (!previousJobs.empty()) {
        ss << "\nПредыдущие места работы:";
        for (const auto& job : previousJobs) {
            ss << "\n  - " << job.company << " (" << job.position 
               << ", " << job.period << ", " << job.years << " лет)";
        }
    }
    
    return ss.str();
}

std::string Employee::getType() const {
    return "Employee";
}

std::string Employee::getPosition() const {
    return position;
}

double Employee::getSalaryRate() const {
    return salaryRate;
}

bool Employee::getOnRegularVacation() const {
    return onRegularVacation;
}

bool Employee::getOnChildcareLeave() const {
    return onChildcareLeave;
}

const std::vector<PreviousJob>& Employee::getPreviousJobs() const {
    return previousJobs;
}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

void Employee::setSalaryRate(double salaryRate) {
    this->salaryRate = salaryRate;
}

void Employee::setOnRegularVacation(bool onRegularVacation) {
    this->onRegularVacation = onRegularVacation;
}

void Employee::setOnChildcareLeave(bool onChildcareLeave) {
    this->onChildcareLeave = onChildcareLeave;
}

void Employee::addPreviousJob(const PreviousJob& job) {
    previousJobs.push_back(job);
}

void Employee::removePreviousJob(int index) {
    if (index >= 0 && index < previousJobs.size()) {
        previousJobs.erase(previousJobs.begin() + index);
    }
}

void Employee::clearPreviousJobs() {
    previousJobs.clear();
}

std::vector<std::shared_ptr<Employee>> Employee::filterByPosition(
    const std::vector<std::shared_ptr<Employee>>& employees,
    const std::string& position) {
    
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        if (employee->getPosition() == position) {
            result.push_back(employee);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Employee>> Employee::filterBySalaryRateRange(
    const std::vector<std::shared_ptr<Employee>>& employees,
    double minRate, double maxRate) {
    
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        double rate = employee->getSalaryRate();
        if (rate >= minRate && rate <= maxRate) {
            result.push_back(employee);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Employee>> Employee::filterByHasChildren(
    const std::vector<std::shared_ptr<Employee>>& employees,
    bool hasChildren) {
    
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        if (employee->getHasChildren() == hasChildren) {
            result.push_back(employee);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Employee>> Employee::filterByPensioners(
    const std::vector<std::shared_ptr<Employee>>& employees,
    bool isPensioner) {
    
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        if (employee->getIsPensioner() == isPensioner) {
            result.push_back(employee);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Employee>> Employee::filterByRegularVacation(
    const std::vector<std::shared_ptr<Employee>>& employees,
    bool onVacation) {
    
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        if (employee->getOnRegularVacation() == onVacation) {
            result.push_back(employee);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Employee>> Employee::filterByChildcareLeave(
    const std::vector<std::shared_ptr<Employee>>& employees,
    bool onLeave) {
    
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        if (employee->getOnChildcareLeave() == onLeave) {
            result.push_back(employee);
        }
    }
    return result;
}
