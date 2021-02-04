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
struct Employee;
struct Developer;
struct SalesManager;

struct EmployeeVisitor {  // !!
    virtual void visit(const Developer &d) = 0;
    virtual void visit(const SalesManager &sm) = 0;
};

// Если у нас много наследников и они иногда добавляются, можно добавить
// реализацию по умолчанию. Тогда требование: либо реализуйте общий случай, либо
// каждый из наследников. Но можно реализовать и общий случай, и одного
// конкретного наследника. Тогда для неизвестных наследников будет общий случай.
struct SimplifiedEmployeeVisitor : EmployeeVisitor {
    virtual void visit(const Employee &e);
    void visit(const Developer &d) override;
    void visit(const SalesManager &sm) override;
};

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

    friend std::ostream &operator<<(
        std::ostream &os,
        const Employee &e);  // !! Делаем через visitor.

    // !!
    //    template<typename F>
    //    virtual void accept(F functor) = 0;  // Нельзя :(
    //    virtual void accept(
    //        void (*do_developer)(const Developer&),
    //        void (*do_sales_manager)(const SalesManager&)
    //    );  // Можно, но длинно.
    virtual void accept(EmployeeVisitor &v) const = 0;

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

    void accept(EmployeeVisitor &v) const override {  // !!
        v.visit(*this);  // Реализация всегда одинаковая, *this уже правильного
                         // типа.
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
};

struct SalesManager : Employee {
    Region region;

    explicit SalesManager(std::string first_name_,
                          std::string last_name_,
                          Region region_)  // explicit!
        : Employee(std::move(first_name_), std::move(last_name_)),
          region(region_) {
    }

    void accept(EmployeeVisitor &v) const override {
        v.visit(*this);  // Реализация всегда одинаковая, *this уже правильного
                         // типа.
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
};

inline void SimplifiedEmployeeVisitor::visit(const Employee &e) {  // !!
    e.accept(*this);
}

inline void SimplifiedEmployeeVisitor::visit(const Developer &d) {  // !!
    visit(static_cast<const Employee &>(d));
}

inline void SimplifiedEmployeeVisitor::visit(const SalesManager &sm) {  // !!
    visit(static_cast<const Employee &>(sm));
}

inline std::ostream &operator<<(std::ostream &os, const Employee &e) {
#if 0
    // Можно, но длинно и можно забыть какой-то if.
    if (const Developer *d = dynamic_cast<const Developer*>(&e); d) {
        // d->operator<<(os);  // d << os
        os << *d;
    } else if (const SalesManager *sm = dynamic_cast<const SalesManager*>(&e); sm) {
        os << *sm;
    } else {
        assert(false);
    }
#endif
    struct EmployeePrintVisitor : EmployeeVisitor {
        std::ostream &os;
        EmployeePrintVisitor(std::ostream &os_) : os(os_) {
        }

        void visit(const Developer &d) override {
            os << "Developer " << d.first_name << " " << d.last_name << " "
               << d.language;
        }
        void visit(const SalesManager &sm) override {
            os << "SalesManager " << sm.first_name << " " << sm.last_name << " "
               << sm.region;
        }
    } v(os);
    e.accept(v);
    return os;
}

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
