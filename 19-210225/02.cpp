#include <iostream>

struct Field {
    int id;
    Field(int id_) : id(id_) {
        std::cout << "Field " << id << "\n";
    }
    ~Field() {
        std::cout << "~Field " << id << "\n";
    }
};

struct Employee {
    Field emp{1};

    Employee() {
        std::cout << "Employee " << this << "\n";
    } 
    Employee(int id) {
        std::cout << "Employee " << id << " " << this << "\n";
    }
    ~Employee() {
        std::cout << "~Employee\n";
    }
};

struct Developer : virtual Employee {
    Field emp{2};

    Developer() : Employee(10) {  // Так написано неявно.
        std::cout << "Developer\n";
    }
    ~Developer() {
        std::cout << "~Developer\n";
    }
};

struct Manager : virtual Employee {
    Field emp{3};

    Manager() : Employee(20) {  // Так написано неявно.
        std::cout << "Manager\n";
//        throw 0;
    }
    ~Manager() {
        std::cout << "~Manager\n";
    }
};

struct LeadDeveloper : Manager, Developer {
    Field emp{4};

    LeadDeveloper() {
        std::cout << "LeadDeveloper\n";
    }
    ~LeadDeveloper() {
        std::cout << "~LeadDeveloper\n";
    }
};

int main() {
    try {
//        Manager m;
        LeadDeveloper ld;
    } catch (int) {
        std::cout << "exception\n";
    }
}
