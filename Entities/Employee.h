#pragma once
#include "person.h"
#include <string>
#include <vector>

struct PreviousJob {
    std::string company;
    std::string position;
    int years;
    std::string period;
};

class Employee : public Person {
private:
    std::string position;
    double salaryRate;
    bool onRegularVacation;
    bool onChildcareLeave;
    std::vector<PreviousJob> previousJobs;
    
public:
    Employee(const std::string& firstName, const std::string& lastName, 
             const std::string& middleName, int age, const std::string& id,
             const std::string& position, double salaryRate,
             bool hasChildren = false, bool isPensioner = false, bool isDisabled = false,
             bool onRegularVacation = false, bool onChildcareLeave = false);
    
    std::string getInfo() const override;
    std::string getType() const override;
    
    std::string getPosition() const;
    double getSalaryRate() const;
    bool getOnRegularVacation() const;
    bool getOnChildcareLeave() const;
    const std::vector<PreviousJob>& getPreviousJobs() const;
    
    void setPosition(const std::string& position);
    void setSalaryRate(double salaryRate);
    void setOnRegularVacation(bool onRegularVacation);
    void setOnChildcareLeave(bool onChildcareLeave);
    
    void addPreviousJob(const PreviousJob& job);
    void removePreviousJob(int index);
    void clearPreviousJobs();
    
    static std::vector<std::shared_ptr<Employee>> filterByPosition(
        const std::vector<std::shared_ptr<Employee>>& employees,
        const std::string& position);
    
    static std::vector<std::shared_ptr<Employee>> filterBySalaryRateRange(
        const std::vector<std::shared_ptr<Employee>>& employees,
        double minRate, double maxRate);
    
    static std::vector<std::shared_ptr<Employee>> filterByHasChildren(
        const std::vector<std::shared_ptr<Employee>>& employees,
        bool hasChildren);
    
    static std::vector<std::shared_ptr<Employee>> filterByPensioners(
        const std::vector<std::shared_ptr<Employee>>& employees,
        bool isPensioner);
    
    static std::vector<std::shared_ptr<Employee>> filterByRegularVacation(
        const std::vector<std::shared_ptr<Employee>>& employees,
        bool onVacation);
    
    static std::vector<std::shared_ptr<Employee>> filterByChildcareLeave(
        const std::vector<std::shared_ptr<Employee>>& employees,
        bool onLeave);
};
