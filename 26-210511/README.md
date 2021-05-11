1. Установите boost:
  * `sudo apt libboost-all-dev` под Ubuntu
  * `pacman -Su mingw-w64-x86_64-boost` под msys2
  * `pacman -Su boost` под Arch
  * `brew install boost` под macOS
2. Синхронизируйте репозиторий
3. В `lab10-bank/bank_test.cpp` закомментируйте все тесты, кроме `Lots of users`
4. Добавьте простые реализации `ledger`/`user`:
  * У первого только метод `get_or_create_user` и мэп
  * У второго только метод `get_balance()` (возвращает 100).
5. Убедитесь, что тест падает.
6. Добавьте mutex, убедитесь, что тест проходит.
