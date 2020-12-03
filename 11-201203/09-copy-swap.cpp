struct my_vector {
    T *data;
    int length;

    my_vector(const my_vector&) : .... {}
    my_vector(my_vector&&) : .... {}
    ~my_vector() {}

    #if 0
    my_vector& operator=(const my_vector &other) {
       // что-то вроде ~my_vector();
       // что-то вроде my_vector(other);
    }

    my_vector& operator=(my_vector &&other) {
       // что-то вроде ~my_vector();
       // что-то вроде my_vector(std::move(other));
    }
    #else
    my_vector& operator=(my_vector other) {
        using std::swap;
        swap(data, other.data);
        swap(length, other.length);
        return *this;
    }
    #endif
};
