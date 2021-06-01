#ifndef CONDITIONAL_H_
#define CONDITIONAL_H_

namespace cls_conditional {
template <bool, typename T, typename>
struct conditional {
    using type = T;
};

template <typename T, typename F>
struct conditional<false, T, F> {
    using type = F;
};

template <bool V, typename T, typename F>
using conditional_t = typename conditional<V, T, F>::type;
}  // namespace cls_conditional

#endif  // CONDITIONAL_H_
