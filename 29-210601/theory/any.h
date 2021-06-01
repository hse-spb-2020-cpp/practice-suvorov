struct any {
    Наивная версия:
    void *obj;
    Но на самом деле не произвольный obj, а хотим делать с obj операции:
    1. Копировать
    2. Узнавать тип (возвращать const type_info&)
    3. Удалять

    Это "динамический полиморфизм" (привет от lab06-employees и виртуальных функций).
    То есть на самом деле хотим хранить Base *obj, где Base:

    struct Base {
        virtual unique_ptr<Base> clone();
        virtual ??? getType();
        virtual ~Base();
    };

    // TODO: сделать шаблоном.
    struct DerivedInt : Base {
        int value;
        clone() { return make_unique<DerivedInt>(value); }
    };

    А ещё точнее - хотим unique_ptr<Base>, потому что мы владеем DerivedInt.
};
