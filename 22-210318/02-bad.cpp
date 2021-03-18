#include <json-c/json.h>
#include <iostream>

int main() {
    json_object *result = json_object_new_array();  // []
    json_object *my_name = json_object_new_object();  // {}
    json_object_object_add(my_name, "name", json_object_new_string("Egor"));
    json_object_object_add(my_name, "surname", json_object_new_string("Suvorov"));

    json_object_array_add(result, my_name);
    // Ой: my_name мы уже вообще не владеем. Он уже может быть даже удалён.
    // json_object_array_add(result, my_name);

    std::cout << json_object_to_json_string_ext(result, JSON_C_TO_STRING_PRETTY);

    // Ой: my_name мы всё ещё не владеем.
    json_object_put(my_name);
    json_object_put(result);
}
