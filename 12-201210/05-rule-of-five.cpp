template<typename T>
struct almost_vector {
     T *ptr;
     int length;
     
     // Не совсем корректно, идеи показывает, но деталей не хватает.
     almost_vector(int length_) : ptr(new T[length_]), length(length_) {}
     // Правило пяти (rule of five):
     //     Если реализовали хотя бы одну из пяти штук ниже, то надо реализовать все.
     //     Например, могли что-то `= delete`.
     // Пример: unique_ptr, shared_ptr, vector...
     almost_vector(const almost_vector &other)
         : ptr(new T[other.length])
         , length(other.length)
     {
         for (int i = 0; i < other.length; i++) {
             ptr[i] = other.ptr[i];
         }
         // std::copy(other.ptr, other.ptr + other.length, ptr);
     }
     almost_vector(almost_vector &&other)
         : ptr(std::exchange(other.ptr, nullptr))
         , length(std::exchange(other.length, 0))
     {
     }
     almost_vector& operator=(const almost_vector &other) {
         // if (*this == other) {  // WTF, slow.
         if (this == &other) {
             return *this;
         }
         // ~almost_vector()
         delete[] ptr;
         // almost_vector(const almost_vector &)
         ptr = new T[other.length];
         length = other.length;
         for (int i = 0; i < other.length; i++) {
             ptr[i] = other.ptr[i];
         }
         return *this;
     }
     almost_vector& operator=(almost_vector &&other) {
         if (this == &other) {  // В стандарте вроде бы(?) не требуется: self-move в стандартных контейнерах запрещён.
             return *this;
         }
         // ~almost_vector()
         delete[] ptr;
         // almost_vector(almost_vector &&)
         ptr = std::exchange(other.ptr, nullptr);
         length = std::exchange(other.length, 0);
         return *this;
     }
     ~almost_vector() {
         delete[] ptr;
     }
};

// Зачем может быть полезен self-move:
template<typename T>
void my_swap(T &a, T &b) {
    T t = std::move(a);
    a = std::move(b);
    b = std::move(t);
}

int main() {
    #if 0
    vector<int> a(10), b;
    memcpy(&b, &a, sizeof a);
    //
    b.ptr = a.ptr;
    b.length = a.length;
    // UB: double free of a.ptr/b.ptr
    #endif
}
