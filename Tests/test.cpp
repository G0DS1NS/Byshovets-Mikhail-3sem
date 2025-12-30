#include <gtest/gtest.h>
#include <memory>
#include "Employee.h"
#include "HRDepartment.h"

class HRDepartmentTests : public ::testing::Test {
protected:
    void SetUp() override {
        employee1 = std::make_shared<Employee>(
            "Тест", "Сотрудник1", "Тестович", 30, "TEST001",
            "Тестер", 1.0, true, false, false, false, false);
        
        employee2 = std::make_shared<Employee>(
            "Тест", "Сотрудник2", "Тестович", 65, "TEST002",
            "Директор", 2.0, false, true, false, true, false);
        
        hr.addEmployee(employee1);
        hr.addEmployee(employee2);
    }
    
    HRDepartment hr;
    std::shared_ptr<Employee> employee1;
    std::shared_ptr<Employee> employee2;
};

TEST_F(HRDepartmentTests, EmployeeCreation) {
    EXPECT_EQ(employee1->getFullName(), "Сотрудник1 Тест Тестович");
    EXPECT_EQ(employee1->getPosition(), "Тестер");
    EXPECT_EQ(employee1->getSalaryRate(), 1.0);
    EXPECT_EQ(employee1->getType(), "Employee");
}

TEST_F(HRDepartmentTests, HRDepartmentAddRemove) {
    EXPECT_EQ(hr.getTotalEmployees(), 2);
    
    hr.removeEmployee("TEST001");
    EXPECT_EQ(hr.getTotalEmployees(), 1);
    
    hr.removeEmployee("TEST002");
    EXPECT_EQ(hr.getTotalEmployees(), 0);
}

TEST_F(HRDepartmentTests, FilterFunctions) {
    auto withChildren = hr.getEmployeesWithChildren();
    EXPECT_EQ(withChildren.size(), 1);
    
    auto pensioners = hr.getPensioners();
    EXPECT_EQ(pensioners.size(), 1);
    
    auto onVacation = hr.getEmployeesOnRegularVacation();
    EXPECT_EQ(onVacation.size(), 1);
}

TEST_F(HRDepartmentTests, PersonPolymorphism) {
    std::vector<std::shared_ptr<Person>> people;
    people.push_back(employee1);
    people.push_back(employee2);
    
    EXPECT_EQ(people[0]->getType(), "Employee");
    EXPECT_EQ(people[1]->getType(), "Employee");
    
    EXPECT_FALSE(people[0]->getInfo().empty());
    EXPECT_FALSE(people[1]->getInfo().empty());
}

TEST_F(HRDepartmentTests, UpdateFunctions) {
    hr.updateSalaryRate("TEST001", 1.5);
    hr.updatePosition("TEST001", "Старший тестер");
    hr.assignRegularVacation("TEST001", true);
    
    auto updatedEmployee = hr.findEmployee("TEST001");
    EXPECT_EQ(updatedEmployee->getSalaryRate(), 1.5);
    EXPECT_EQ(updatedEmployee->getPosition(), "Старший тестер");
    EXPECT_TRUE(updatedEmployee->getOnRegularVacation());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
