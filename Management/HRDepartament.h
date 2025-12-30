#pragma once
#include "Employee.h"
#include <vector>
#include <memory>
#include <string>

class HRDepartment {
private:
    std::vector<std::shared_ptr<Employee>> employees;
    
public:
    HRDepartment() = default;
    
    void addEmployee(const std::shared_ptr<Employee>& employee);
    void removeEmployee(const std::string& employeeId);
    
    std::shared_ptr<Employee> findEmployee(const std::string& employeeId) const;
    std::vector<std::shared_ptr<Employee>> findEmployeesByFullName(const std::string& fullName) const;
    
    std::vector<std::shared_ptr<Employee>> getAllEmployees() const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByPosition(const std::string& position) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesBySalaryRateRange(double minRate, double maxRate) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesWithChildren() const;
    std::vector<std::shared_ptr<Employee>> getPensioners() const;
    std::vector<std::shared_ptr<Employee>> getEmployeesOnRegularVacation() const;
    std::vector<std::shared_ptr<Employee>> getEmployeesOnChildcareLeave() const;
    
    std::vector<std::string> getAllPositions() const;
    std::vector<std::shared_ptr<Employee>> getEmployeesWithPreviousJobs() const;
    
    int getTotalEmployees() const;
    int getTotalOnVacation() const;
    int getTotalOnChildcareLeave() const;
    int getTotalPensioners() const;
    int getTotalWithChildren() const;
    
    void assignRegularVacation(const std::string& employeeId, bool onVacation);
    void assignChildcareLeave(const std::string& employeeId, bool onLeave);
    void updateSalaryRate(const std::string& employeeId, double newRate);
    void updatePosition(const std::string& employeeId, const std::string& newPosition);
};
