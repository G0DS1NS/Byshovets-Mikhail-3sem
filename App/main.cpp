#include <iostream>
#include <memory>
#include <vector>
#include "person.h"
#include "Employee.h"
#include "HRDepartment.h"

void printSeparator() {
    std::cout << "--------------------------------------------------\n";
}

void printInfo(const std::vector<std::shared_ptr<Person>>& people) {
    for (const auto& person : people) {
        printSeparator();
        std::cout << "Тип: " << person->getType() << "\n";
        std::cout << person->getInfo() << "\n";
    }
    printSeparator();
}

void demonstrateHRFunctions(HRDepartment& hr) {
    std::cout << "\n ДЕМОНСТРАЦИЯ ФУНКЦИЙ ОТДЕЛА КАДРОВ \n";
    
    printSeparator();
    std::cout << "1. Все сотрудники:\n";
    auto allEmployees = hr.getAllEmployees();
    for (const auto& employee : allEmployees) {
        std::cout << "- " << employee->getFullName() 
                  << " (" << employee->getPosition() 
                  << ", ставка: " << employee->getSalaryRate() << ")\n";
    }
    
    printSeparator();
    std::cout << "2. Сотрудники по должности 'Программист':\n";
    auto programmers = hr.getEmployeesByPosition("Программист");
    for (const auto& employee : programmers) {
        std::cout << "- " << employee->getFullName() << "\n";
    }
    
    printSeparator();
    std::cout << "3. Сотрудники с детьми:\n";
    auto employeesWithChildren = hr.getEmployeesWithChildren();
    for (const auto& employee : employeesWithChildren) {
        std::cout << "- " << employee->getFullName() << "\n";
    }
    
    printSeparator();
    std::cout << "4. Пенсионеры:\n";
    auto pensioners = hr.getPensioners();
    for (const auto& employee : pensioners) {
        std::cout << "- " << employee->getFullName() << "\n";
    }
    
    printSeparator();
    std::cout << "5. Сотрудники в очередном отпуске:\n";
    auto onVacation = hr.getEmployeesOnRegularVacation();
    for (const auto& employee : onVacation) {
        std::cout << "- " << employee->getFullName() << "\n";
    }
    
    printSeparator();
    std::cout << "6. Сотрудники в отпуске по уходу за ребенком:\n";
    auto onChildcareLeave = hr.getEmployeesOnChildcareLeave();
    for (const auto& employee : onChildcareLeave) {
        std::cout << "- " << employee->getFullName() << "\n";
    }
    
    printSeparator();
    std::cout << "7. Все должности в компании:\n";
    auto allPositions = hr.getAllPositions();
    for (const auto& position : allPositions) {
        std::cout << "- " << position << "\n";
    }
    
    printSeparator();
    std::cout << "8. Сотрудники с предыдущими местами работы:\n";
    auto withPreviousJobs = hr.getEmployeesWithPreviousJobs();
    for (const auto& employee : withPreviousJobs) {
        std::cout << "- " << employee->getFullName() << "\n";
        const auto& jobs = employee->getPreviousJobs();
        for (const auto& job : jobs) {
            std::cout << "  * " << job.company << " - " << job.position 
                      << " (" << job.period << ")\n";
        }
    }
}

int main() {
    std::cout << " СИСТЕМА УПРАВЛЕНИЯ ОТДЕЛОМ КАДРОВ \n";
    
    std::vector<std::shared_ptr<Person>> people;
    
    auto employee1 = std::make_shared<Employee>(
        "Иван", "Иванов", "Иванович", 35, "E001",
        "Программист", 1.5, true, false, false, false, false);
    
    auto employee2 = std::make_shared<Employee>(
        "Мария", "Петрова", "Сергеевна", 42, "E002",
        "Бухгалтер", 1.2, true, false, false, true, false);
    
    auto employee3 = std::make_shared<Employee>(
        "Анна", "Сидорова", "Петровна", 28, "E003",
        "Менеджер", 1.0, false, false, false, false, true);
    
    auto employee4 = std::make_shared<Employee>(
        "Дмитрий", "Фёдоров", "Александрович", 65, "E004",
        "Директор", 2.5, true, true, false, false, false);
    
    auto employee5 = std::make_shared<Employee>(
        "Елена", "Козлова", "Михайловна", 45, "E005",
        "Программист", 1.8, true, false, true, false, false);
    
    PreviousJob job1{"IT Company", "Junior Developer", 3, "2015-2018"};
    PreviousJob job2{"Tech Solutions", "Senior Developer", 5, "2018-2023"};
    employee1->addPreviousJob(job1);
    employee1->addPreviousJob(job2);
    
    PreviousJob job3{"Finance Corp", "Accountant", 10, "2010-2020"};
    employee2->addPreviousJob(job3);
    
    people.push_back(employee1);
    people.push_back(employee2);
    people.push_back(employee3);
    people.push_back(employee4);
    people.push_back(employee5);
    
    HRDepartment hr;
    hr.addEmployee(employee1);
    hr.addEmployee(employee2);
    hr.addEmployee(employee3);
    hr.addEmployee(employee4);
    hr.addEmployee(employee5);
    
    std::cout << "\nИТЕРАЦИЯ ПО КОЛЛЕКЦИИ ЛЮДЕЙ \n";
    printInfo(people);
    
    demonstrateHRFunctions(hr);
    
    printSeparator();
    std::cout << "СТАТИСТИКА ОТДЕЛА КАДРОВ:\n"; 
    std::cout << "Всего сотрудников: " 
              << hr.getTotalEmployees() << "\n";
    std::cout << "Сотрудников с детьми: " 
              << hr.getTotalWithChildren() << "\n";
    std::cout << "Пенсионеров: "
              << hr.getTotalPensioners() << "\n";
    std::cout << "В очередном отпуске: "
              << hr.getTotalOnVacation() << "\n";
    std::cout << "В отпуске по уходу за ребенком: "
              << hr.getTotalOnChildcareLeave() << "\n";
    
    return 0;
}
