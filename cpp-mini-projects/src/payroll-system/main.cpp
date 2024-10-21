#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/connection.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace sql;

class Employee {
public:
    std::string name;
    double hourlyRate;
    double hoursWorked;

    Employee(const std::string& n, double rate) : name(n), hourlyRate(rate), hoursWorked(0.0) {}

    double calculateSalary() const {
        return hourlyRate * hoursWorked;
    }
};

class PayrollSystem {
private:
    std::vector<Employee> employees;
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;

public:
    PayrollSystem() : driver(get_driver_instance()), con(driver->connect("tcp://127.0.0.1:3306", "root", "")) {
        con->setSchema("cpp_payroll");
        createEmployeeTable();
        retrieveEmployeesFromDatabase();
    }

    ~PayrollSystem() {
        delete con;
    }

    void addEmployee(const Employee& emp) {
        employees.push_back(emp);
        saveEmployeeToDatabase(emp);
    }

    void recordHoursWorked(const std::string& empName, double hours) {
        auto it = std::find_if(employees.begin(), employees.end(),
                               [empName](const Employee& emp) { return emp.name == empName; });

        if (it != employees.end()) {
            it->hoursWorked += hours;
            updateEmployeeInDatabase(*it);
        } else {
            std::cout << "Employee not found." << std::endl;
        }
    }

    void generatePayrollReport() const {
        std::cout << std::setw(15) << "Employee Name" << std::setw(15) << "Hours Worked" << std::setw(15) << "Salary" << std::endl;
        for (const auto& emp : employees) {
            std::cout << std::setw(15) << emp.name << std::setw(15) << emp.hoursWorked << std::setw(15) << emp.calculateSalary() << std::endl;
        }
    }

private:
    void createEmployeeTable() {
        Statement* stmt = con->createStatement();
        stmt->execute("CREATE TABLE IF NOT EXISTS employees (name VARCHAR(50), hourly_rate DOUBLE, hours_worked DOUBLE)");
        delete stmt;
    }

    void saveEmployeeToDatabase(const Employee& emp) {
        PreparedStatement* pstmt = con->prepareStatement("INSERT INTO employees (name, hourly_rate, hours_worked) VALUES (?, ?, ?)");
        pstmt->setString(1, emp.name);
        pstmt->setDouble(2, emp.hourlyRate);
        pstmt->setDouble(3, emp.hoursWorked);
        pstmt->execute();
        delete pstmt;
    }

    void updateEmployeeInDatabase(const Employee& emp) {
        PreparedStatement* pstmt = con->prepareStatement("UPDATE employees SET hours_worked = ? WHERE name = ?");
        pstmt->setDouble(1, emp.hoursWorked);
        pstmt->setString(2, emp.name);
        pstmt->execute();
        delete pstmt;
    }

    void retrieveEmployeesFromDatabase() {
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT * FROM employees");
        while (res->next()) {
            std::string name = res->getString("name");
            double hourlyRate = res->getDouble("hourly_rate");
            Employee emp(name, hourlyRate);
            emp.hoursWorked = res->getDouble("hours_worked");
            employees.push_back(emp);
        }
        delete res;
        delete stmt;
    }
};

int main() {
    PayrollSystem payroll;

    std::string name;
    double hourlyRate;
    double hoursWorked;

    // Input employee details
    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);

    std::cout << "Enter hourly rate: ";
    std::cin >> hourlyRate;

    std::cout << "Enter hours worked: ";
    std::cin >> hoursWorked;

    // Add new employee
    Employee newEmployee(name, hourlyRate);
    payroll.addEmployee(newEmployee);
    payroll.recordHoursWorked(name, hoursWorked);

    // Generate and display payroll report
    payroll.generatePayrollReport();

    return 0;
}
