#include <iostream>
#include "Array.hpp"

int main() {
	try {
		std::cout << "=== Teste 1: Array de int ===" << std::endl;
		Array<int> arrInt(5);
		for (unsigned int i = 0; i < arrInt.size(); i++)
			arrInt[i] = i * 10;

		for (unsigned int i = 0; i < arrInt.size(); i++)
			std::cout << "arrInt[" << i << "] = " << arrInt[i] << std::endl;

		std::cout << "\n=== Teste 2: Cópia de Array ===" << std::endl;
		Array<int> arrCopy(arrInt);
		for (unsigned int i = 0; i < arrCopy.size(); i++)
			std::cout << "arrCopy[" << i << "] = " << arrCopy[i] << std::endl;

		std::cout << "\n=== Teste 3: Atribuição ===" << std::endl;
		Array<int> arrAssign;
		arrAssign = arrInt;
		for (unsigned int i = 0; i < arrAssign.size(); i++)
			std::cout << "arrAssign[" << i << "] = " << arrAssign[i] << std::endl;

		std::cout << "\n=== Teste 4: Array de strings ===" << std::endl;
		Array<std::string> arrStr(3);
		arrStr[0] = "C++";
		arrStr[1] = "é";
		arrStr[2] = "legal!";
		for (unsigned int i = 0; i < arrStr.size(); i++)
			std::cout << arrStr[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Teste 5: Exceção (índice fora do limite) ===" << std::endl;
		std::cout << arrInt[10] << std::endl; // deve lançar exceção

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
