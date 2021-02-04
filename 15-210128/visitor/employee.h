#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include "employee_enums.h"

namespace employee {
struct Employee {
    std::string first_name;
    std::string last_name;

protected:  // !
    Employee(const Employee &) = default;
    Employee(Employee &&) = default;
    Employee &operator=(const Employee &) = default;
    Employee &operator=(Employee &&) = default;

public:
    virtual ~Employee() = default;

    friend std::ostream &operator<<(std::ostream &os, const Employee &e) {
        e.printTo(os);
        return os;
    }

    // private:  // В учебной обстановке printTo() тестируется отдельно и должен
    // быть публичным.
    virtual void printTo(std::ostream &) const = 0;  // = 0!

    static std::unique_ptr<Employee> readFrom(std::istream &is);

protected:  // !
    explicit Employee(std::string first_name_,
                      std::string last_name_)  // explicit!
        : first_name(std::move(first_name_)), last_name(std::move(last_name_)) {
    }
};

struct Developer : Employee {
    ProgrammingLanguage language;

    explicit Developer(std::string first_name_,
                       std::string last_name_,
                       ProgrammingLanguage language_)  // explicit!
        : Employee(std::move(first_name_), std::move(last_name_)),
          language(language_) {
    }

    static Developer readFrom(std::istream &is) {
        std::string first_name_;
        std::string last_name_;
        ProgrammingLanguage language_;
        is >> first_name_ >> last_name_ >> language_;
        assert(is);
        return Developer(std::move(first_name_), std::move(last_name_),
                         language_);
    }

    // private:
    void printTo(std::ostream &os) const override {
        os << "Developer " << first_name << " " << last_name << " " << language;
    }
};

struct SalesManager : Employee {
    Region region;

    explicit SalesManager(std::string first_name_,
                          std::string last_name_,
                          Region region_)  // explicit!
        : Employee(std::move(first_name_), std::move(last_name_)),
          region(region_) {
    }

    static SalesManager readFrom(std::istream &is) {
        std::string first_name_;
        std::string last_name_;
        Region region_;
        is >> first_name_ >> last_name_ >> region_;
        assert(is);
        return SalesManager(std::move(first_name_), std::move(last_name_),
                            region_);
    }

    // private:
    void printTo(std::ostream &os) const override {
        os << "SalesManager " << first_name << " " << last_name << " "
           << region;
    }
};

inline std::unique_ptr<Employee> Employee::readFrom(std::istream &is) {
    std::string type;
    is >> type;
    assert(is);
    if (type == "Developer") {
        return std::make_unique<Developer>(Developer::readFrom(is));
    } else if (type == "SalesManager") {
        return std::make_unique<SalesManager>(SalesManager::readFrom(is));
    } else {
        std::abort();
    }
}
}  // namespace employee

#endif  // EMPLOYEE_H_
