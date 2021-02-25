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
    ~Employee() {
        std::cout << "~Employee\n";
    }
};

struct Developer : Employee {
    Field emp{2};

    Developer() {
        std::cout << "Developer\n";
    }
    ~Developer() {
        std::cout << "~Developer\n";
    }
};

struct Manager : Employee {
    Field emp{3};

    Manager() {
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
        LeadDeveloper ld;
    } catch (int) {
        std::cout << "exception\n";
    }
}
