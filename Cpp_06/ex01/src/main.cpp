
#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"
#include <iostream>

int main(void)
{
    Data data;
    data.number = 42;
    data.name = "hello";

    std::cout << "Original pointer : " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized       : " << raw << std::endl;

    Data *result = Serializer::deserialize(raw);
    std::cout << "Deserialized     : " << result << std::endl;

    if (result == &data)
        std::cout << "OK : pointeurs identiques !" << std::endl;
    else
        std::cout << "KO : pointeurs differents !" << std::endl;

    std::cout << "data.number : " << result->number << std::endl;
    std::cout << "data.name   : " << result->name << std::endl;

    return 0;
}
