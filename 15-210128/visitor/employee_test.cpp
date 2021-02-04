#include "employee.h"
#include <memory>
#include <sstream>
#include <type_traits>
#include <vector>
#include "doctest.h"

#define TEST_BASIC
#define TEST_INHERITANCE
#define TEST_POLYMORPHIC_VECTOR
#define TEST_PRINT_TO
#define TEST_OUT_OPERATOR
#define TEST_READ_FROM_SINGLE
#define TEST_READ_FROM_FACTORY
#define TEST_NO_SLICING

#ifdef TEST_BASIC
TEST_CASE("There is no default constructor") {
    CHECK(!std::is_default_constructible_v<employee::Employee>);
    CHECK(!std::is_default_constructible_v<employee::Developer>);
    CHECK(!std::is_default_constructible_v<employee::SalesManager>);
}

TEST_CASE("Developer constructors") {
    employee::Developer a("Ivan", "Ivanov",
                          employee::ProgrammingLanguage::Java);
    CHECK(a.first_name == "Ivan");
    CHECK(a.last_name == "Ivanov");
    CHECK(a.language == employee::ProgrammingLanguage::Java);

    employee::Developer b = a;
    CHECK(b.first_name == "Ivan");
    CHECK(b.last_name == "Ivanov");
    CHECK(b.language == employee::ProgrammingLanguage::Java);

    b = a;
    CHECK(b.first_name == "Ivan");
    CHECK(b.last_name == "Ivanov");
    CHECK(b.language == employee::ProgrammingLanguage::Java);
}

TEST_CASE("SalesManager constructors") {
    employee::SalesManager a("Petr", "Petrov", employee::Region::Russia);
    CHECK(a.first_name == "Petr");
    CHECK(a.last_name == "Petrov");
    CHECK(a.region == employee::Region::Russia);

    employee::SalesManager b = a;
    CHECK(b.first_name == "Petr");
    CHECK(b.last_name == "Petrov");
    CHECK(b.region == employee::Region::Russia);

    b = a;
    CHECK(b.first_name == "Petr");
    CHECK(b.last_name == "Petrov");
    CHECK(b.region == employee::Region::Russia);
}
#endif  // TEST_BASIC

#ifdef TEST_INHERITANCE
TEST_CASE("Ref-compatibility with Employee") {
    auto check_employee = [](const employee::Employee &e) {
        CHECK(e.first_name == "Ideal");
        CHECK(e.last_name == "Idealov");
    };

    SUBCASE("Developer") {
        check_employee(employee::Developer("Ideal", "Idealov",
                                           employee::ProgrammingLanguage::Cpp));
    }

    SUBCASE("SalesManager") {
        check_employee(
            employee::SalesManager("Ideal", "Idealov", employee::Region::EU));
    }
}
#endif  // TEST_INHERITANCE

#ifdef TEST_POLYMORPHIC_VECTOR
TEST_CASE("Polymorphic vector") {
    std::vector<std::unique_ptr<employee::Employee>> es;
    es.emplace_back(std::make_unique<employee::Developer>(
        "Igor", "Igorev", employee::ProgrammingLanguage::Cpp));
    es.emplace_back(std::make_unique<employee::SalesManager>(
        "Fedor", "Fedorov", employee::Region::US));
}
#endif  // TEST_POLYMORPHIC_VECTOR

#ifdef TEST_PRINT_TO
TEST_CASE("printTo()") {
    auto printTo = [](const employee::Employee &e, std::ostream &os) {
        e.printTo(os);
    };

    SUBCASE("Developer") {
        std::stringstream ss;
        printTo(employee::Developer("Igor", "Igorev",
                                    employee::ProgrammingLanguage::Python),
                ss);
        CHECK(ss.str() == "Developer Igor Igorev Python");
    }

    SUBCASE("SalesManager") {
        std::stringstream ss;
        printTo(employee::SalesManager("Igor", "Igorev", employee::Region::EU),
                ss);
        CHECK(ss.str() == "SalesManager Igor Igorev EU");
    }
}
#endif  // TEST_PRINT_TO

#ifdef TEST_OUT_OPERATOR
TEST_CASE("operator<<") {
    SUBCASE("Developer") {
        std::stringstream ss;
        employee::Developer d("Igor", "Igorev",
                              employee::ProgrammingLanguage::Python);

        const employee::Employee &e = d;
        ss << ">" << e << "<";

        CHECK(ss);
        CHECK(ss.str() == ">Developer Igor Igorev Python<");
    }

    SUBCASE("SalesManager") {
        std::stringstream ss;
        employee::SalesManager s("Igor", "Igorev", employee::Region::EU);

        const employee::Employee &e = s;
        ss << ">" << e << "<";

        CHECK(ss);
        CHECK(ss.str() == ">SalesManager Igor Igorev EU<");
    }
}
#endif  // TEST_OUT_OPERATOR

#ifdef TEST_READ_FROM_SINGLE
TEST_CASE("readFrom for a single class") {
    SUBCASE("Developer") {
        std::stringstream ss("Igor Igorev C++ 123");

        employee::Developer e = employee::Developer::readFrom(ss);
        CHECK(e.first_name == "Igor");
        CHECK(e.last_name == "Igorev");
        CHECK(e.language == employee::ProgrammingLanguage::Cpp);

        CHECK(ss);
        std::string remaining;
        getline(ss, remaining);
        CHECK(remaining == " 123");
    }

    SUBCASE("SalesManager") {
        std::stringstream ss("Igor Igorev EU 123");

        employee::SalesManager s = employee::SalesManager::readFrom(ss);
        CHECK(s.first_name == "Igor");
        CHECK(s.last_name == "Igorev");
        CHECK(s.region == employee::Region::EU);

        CHECK(ss);
        std::string remaining;
        getline(ss, remaining);
        CHECK(remaining == " 123");
    }
}
#endif  // TEST_READ_FROM_SINGLE

#ifdef TEST_READ_FROM_FACTORY
TEST_CASE("Factory readFrom") {
    SUBCASE("Developer") {
        std::stringstream ss("Developer Igor Igorev C++ 123");

        std::unique_ptr<employee::Employee> e =
            employee::Employee::readFrom(ss);
        CHECK(e->first_name == "Igor");
        CHECK(e->last_name == "Igorev");

        auto *d = dynamic_cast<employee::Developer *>(e.get());
        REQUIRE(d);
        CHECK(d->language == employee::ProgrammingLanguage::Cpp);

        CHECK(ss);
        std::string remaining;
        getline(ss, remaining);
        CHECK(remaining == " 123");
    }

    SUBCASE("SalesManager") {
        std::stringstream ss("SalesManager Igor Igorev EU 123");

        std::unique_ptr<employee::Employee> e =
            employee::Employee::readFrom(ss);
        CHECK(e->first_name == "Igor");
        CHECK(e->last_name == "Igorev");

        auto *s = dynamic_cast<employee::SalesManager *>(e.get());
        REQUIRE(s);
        CHECK(s->region == employee::Region::EU);

        CHECK(ss);
        std::string remaining;
        getline(ss, remaining);
        CHECK(remaining == " 123");
    }
}
#endif  // TEST_READ_FROM_FACTORY

#ifdef TEST_NO_SLICING
TEST_CASE("Copy and move for Employee are non-public to prevent slicing") {
    CHECK(!std::is_copy_constructible_v<employee::Employee>);
    CHECK(!std::is_constructible_v<employee::Employee,
                                   const employee::Developer &>);
    CHECK(!std::is_constructible_v<employee::Employee,
                                   const employee::SalesManager &>);
    CHECK(!std::is_copy_assignable_v<employee::Employee>);
    CHECK(!std::is_assignable_v<employee::Employee &,
                                const employee::Developer &>);
    CHECK(!std::is_assignable_v<employee::Employee &,
                                const employee::SalesManager &>);
}
#endif  // TEST_NO_SLICING
