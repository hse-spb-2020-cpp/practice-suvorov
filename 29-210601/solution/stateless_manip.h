#ifndef STATELESS_MANIP_H_
#define STATELESS_MANIP_H_

#include <iostream>

namespace cls_stateless_manip {
namespace impl {
struct writer {
protected:
    int offset;
    const int &x;

public:
    writer(int offset_, const int &x_) : offset(offset_), x(x_) {
    }

    friend std::ostream &operator<<(std::ostream &os, writer &&r) {
        return os << r.x + r.offset;
    }
};

struct reader_writer : writer {
    reader_writer(int offset_, int &x_) : writer(offset_, x_) {
    }

    friend std::istream &operator>>(std::istream &is, reader_writer &&r) {
        int value = 0;
        is >> value;
        const_cast<int &>(r.x) = value - r.offset;
        return is;
    }
};
}  // namespace impl

auto shifted(int offset, const int &x) {
    return impl::writer(offset, x);
}

auto shifted(int offset, int &x) {
    return impl::reader_writer(offset, x);
}
}  // namespace cls_stateless_manip

#endif  // STATELESS_MANIP_H_
