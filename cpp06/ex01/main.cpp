#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    // Criar um objeto Data
    Data originalData;
    originalData.id = 42;
    originalData.name = "Teste";

    // Serializar
    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    // Desserializar
    Data* deserializedData = Serializer::deserialize(raw);

    // Verificar se são o mesmo ponteiro
    if (deserializedData == &originalData) {
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
        std::cout << "Data content: id = " << deserializedData->id
                  << ", name = " << deserializedData->name << std::endl;
    } else {
        std::cout << "Error: Deserialized pointer does not match original pointer." << std::endl;
    }

    return 0;
}