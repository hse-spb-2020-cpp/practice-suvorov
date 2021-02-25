#include <iostream>

class A{
public:
    A(){ std::cout<<"A::A"<<std::endl; }
    virtual ~A(){ std::cout<<"A::~A"<<std::endl; }
};

class B{
public:
    B(){ std::cout<<"B::B"<<std::endl; }
    virtual ~B(){ std::cout<<"B::~B"<<std::endl; }
};

class C{
public:
    C(){ std::cout<<"C::C"<<std::endl; }
    virtual ~C(){ std::cout<<"C::~C"<<std::endl; }
};

class D : A, B{
    C b;
public:
    D(){ std::cout<<"D::D"<<std::endl; throw 0; }
    virtual ~D(){ std::cout<<"D::~D"<<std::endl; }
};

int main()
{
    try{
      D c;
    }catch(...){
    }
    return 0;
}
