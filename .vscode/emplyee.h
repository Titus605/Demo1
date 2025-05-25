#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

// Lớp cơ sở trừu tượng
class EmployeeBase {
protected:
    string* employeeID;   // Mã nhân viên
    string* name;         // Tên nhân viên
    int* age;             // Tuổi

public:
    EmployeeBase(const string& id = "EMP000", const string& n = "Unknown", int a = 0) {
        employeeID = new string(id);
        name = new string(n);
        age = new int(a);
    }

    virtual ~EmployeeBase() {
        delete employeeID;
        delete name;
        delete age;
    }

    virtual void displayInfo() const = 0;

    virtual string getID() const {
        return *employeeID;
    }

    string getName() const {
        return *name;
    }

    int getAge() const {
        return *age;
    }
};

// Lớp dẫn xuất
class Employee : public EmployeeBase {
private:
    double* salary;
    string* position;

public:
    Employee(const string& id = "EMP000", const string& n = "Unknown", int a = 0, double s = 0.0, const string& pos = "Staff")
        : EmployeeBase(id, n, a) {
        salary = new double(s);
        position = new string(pos);
    }

    ~Employee() override {
        delete salary;
        delete position;
    }

    void displayInfo() const override {
        cout << "Ma nhan vien: " << *employeeID << endl;
        cout << "Ten nhan vien: " << *name << endl;
        cout << "Tuoi: " << *age << endl;
        cout << "Chuc vu: " << *position << endl;
        cout << "Luong: " << *salary << " VND" << endl;
    }

    void updateInfo(const string& newName, int newAge) {
        *name = newName;
        *age = newAge;
    }

    void promote(const string& newPosition, double increaseSalary) {
        *position = newPosition;
        *salary += increaseSalary;
    }

    bool operator==(const Employee& other) const {
        return *employeeID == *other.employeeID;
    }

    string getID() const override {
        return "EMP-" + *employeeID;
    }
};

#endif
