#include "HRDepartment.h"
#include <algorithm>

void HRDepartment::addEmployee(const std::shared_ptr<Employee>& employee) {
    if (!employee || findEmployee(employee->getId())) {
        return;
    }
    employees.push_back(employee);
}

void HRDepartment::removeEmployee(const std::string& employeeId) {
    auto it = std::remove_if(employees.begin(), employees.end(),
        [&employeeId](const auto& employee) {
            return employee->getId() == employeeId;
        });
    employees.erase(it, employees.end());
}

std::shared_ptr<Employee> HRDepartment::findEmployee(const std::string& employeeId) const {
    for (const auto& employee : employees) {
        if (employee->getId() == employeeId) {
            return employee;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Employee>> HRDepartment::findEmployeesByFullName(
    const std::string& fullName) const {
    
    return Employee::filterByPosition(employees, fullName);
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getAllEmployees() const {
    return employees;
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getEmployeesByPosition(
    const std::string& position) const {
    
    return Employee::filterByPosition(employees, position);
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getEmployeesBySalaryRateRange(
    double minRate, double maxRate) const {
    
    return Employee::filterBySalaryRateRange(employees, minRate, maxRate);
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getEmployeesWithChildren() const {
    return Employee::filterByHasChildren(employees, true);
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getPensioners() const {
    return Employee::filterByPensioners(employees, true);
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getEmployeesOnRegularVacation() const {
    return Employee::filterByRegularVacation(employees, true);
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getEmployeesOnChildcareLeave() const {
    return Employee::filterByChildcareLeave(employees, true);
}

std::vector<std::string> HRDepartment::getAllPositions() const {
    std::vector<std::string> positions;
    for (const auto& employee : employees) {
        std::string position = employee->getPosition();
        if (std::find(positions.begin(), positions.end(), position) == positions.end()) {
            positions.push_back(position);
        }
    }
    return positions;
}

std::vector<std::shared_ptr<Employee>> HRDepartment::getEmployeesWithPreviousJobs() const {
    std::vector<std::shared_ptr<Employee>> result;
    for (const auto& employee : employees) {
        if (!employee->getPreviousJobs().empty()) {
            result.push_back(employee);
        }
    }
    return result;
}

int HRDepartment::getTotalEmployees() const {
    return static_cast<int>(employees.size());
}

int HRDepartment::getTotalOnVacation() const {
    return static_cast<int>(getEmployeesOnRegularVacation().size());
}

int HRDepartment::getTotalOnChildcareLeave() const {
    return static_cast<int>(getEmployeesOnChildcareLeave().size());
}

int HRDepartment::getTotalPensioners() const {
    return static_cast<int>(getPensioners().size());
}

int HRDepartment::getTotalWithChildren() const {
    return static_cast<int>(getEmployeesWithChildren().size());
}

void HRDepartment::assignRegularVacation(const std::string& employeeId, bool onVacation) {
    auto employee = findEmployee(employeeId);
    if (employee) {
        employee->setOnRegularVacation(onVacation);
    }
}

void HRDepartment::assignChildcareLeave(const std::string& employeeId, bool onLeave) {
    auto employee = findEmployee(employeeId);
    if (employee) {
        employee->setOnChildcareLeave(onLeave);
    }
}

void HRDepartment::updateSalaryRate(const std::string& employeeId, double newRate) {
    auto employee = findEmployee(employeeId);
    if (employee) {
        employee->setSalaryRate(newRate);
    }
}

void HRDepartment::updatePosition(const std::string& employeeId, const std::string& newPosition) {
    auto employee = findEmployee(employeeId);
    if (employee) {
        employee->setPosition(newPosition);
    }
}
