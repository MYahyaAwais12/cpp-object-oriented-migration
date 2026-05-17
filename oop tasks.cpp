/*Task 1*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;

public:
    Student() : id(0), name("Unknown"), gpa(0.0) {}

    Student(int sId, string sName, double sGpa) {
        id = sId;
        name = sName;
        setGpa(sGpa);
    }

    void setId(int sId) { id = sId; }
    void setName(string sName) { name = sName; }
    void setGpa(double sGpa) {
        if (sGpa >= 0.0 && sGpa <= 4.0) {
            gpa = sGpa;
        } else {
            gpa = 0.0;
        }
    }

    int getId() const { return id; }
    string getName() const { return name; }
    double getGpa() const { return gpa; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }

    double calculatePercentage() const {
        return gpa * 25;
    }
};
//Task 2
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string holderName;
    double* balance;

public:
    BankAccount() : accountNumber("N/A"), holderName("N/A") {
        balance = new double(0.0);
    }

    BankAccount(std::string accNum, std::string name, double initialBalance) 
        : accountNumber(accNum), holderName(name) {
        balance = new double(initialBalance >= 0 ? initialBalance : 0.0);
    }

    BankAccount(const BankAccount& other) {
        accountNumber = other.accountNumber;
        holderName = other.holderName;
        balance = new double(*other.balance);
    }

    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            accountNumber = other.accountNumber;
            holderName = other.holderName;
            delete balance;
            balance = new double(*other.balance);
        }
        return *this;
    }

    ~BankAccount() {
        delete balance;
    }

    void deposit(double amount) {
        if (amount > 0) *balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= *balance) {
            *balance -= amount;
        }
    }

    double getBalance() const { return *balance; }
};
// task 3
#include <iostream>

class Temperature {
private:
    double celsius;

    bool validateTemperature(double c) {
        return (c >= -273.15);
    }

public:
    void setCelsius(double c) {
        if (validateTemperature(c)) {
            celsius = c;
        }
    }

    void setFahrenheit(double f) {
        double c = (f - 32) * 5.0 / 9.0;
        if (validateTemperature(c)) {
            celsius = c;
        }
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32;
    }
};