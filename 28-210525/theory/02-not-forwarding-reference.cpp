template<typename R, typename ...Args>
struct CallLog {
    R result;
    std::tuple<Args...> arguments;

    // Это НЕ forwarding reference! Это НЕ perfect forwarding!
    // Причина: тут не включается механизм автовывода типов из аргументов,
    // так как типы уже зафиксированы в CallLog<>.
    // Можно было бы сделать шаблонный конструктор и самостоятельно проверить,
    // что типы совпали, но это много кода и муторно (SFINAE, concepts).
    CallLog(R &&result, Args &&...arguments)
        : result(std::forward<R>(result))
        , arguments(std::forward<Args>(arguments)...) {
    }
    // TODO: CallLog(result, arguments....) consturctor
};
