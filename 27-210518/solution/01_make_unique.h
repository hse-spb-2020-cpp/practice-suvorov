#ifndef MAKE_UNIQUE_H
#define MAKE_UNIQUE_H

#include <memory>
#include <utility>

namespace cls_27 {
template<typename T, typename ...Args>
auto make_unique(Args &&...args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}  // namespace cls_27

#endif  // MAKE_UNIQUE_H
