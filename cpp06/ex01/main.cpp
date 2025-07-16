/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:03:05 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/07/16 18:10:02 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // Criando um objeto Data
    Data data;
    data.id = 42;
    data.name = "Serialization Test";

    std::cout << "===== Original Data =====\n";
    std::cout << "Endereço original: " << &data << "\n";
    std::cout << "id: " << data.id << "\n";
    std::cout << "name: " << data.name << "\n";

    // Serializando: ponteiro -> inteiro
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\nSerializado (uintptr_t): " << raw << "\n";

    // Desserializando: inteiro -> ponteiro
    Data* restored = Serializer::deserialize(raw);

    std::cout << "\n===== After Deserialize =====\n";
    std::cout << "Endereço restaurado: " << restored << "\n";
    std::cout << "id: " << restored->id << "\n";
    std::cout << "name: " << restored->name << "\n";

    // Verificando se é o mesmo ponteiro
    if (restored == &data)
        std::cout << "\n✅ Ponteiros coincidem: serialização bem-sucedida!\n";
    else
        std::cout << "\n❌ Ponteiros diferentes: erro na serialização!\n";

    return 0;
}