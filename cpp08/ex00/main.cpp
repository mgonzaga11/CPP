#include "easyfind.hpp"

int main()
{
	try
	{
		// ===== Teste com std::vector =====
		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i * 10); // 0, 10, 20, 30, 40

		std::cout << "Testando std::vector:" << std::endl;
		std::vector<int>::iterator itVec = easyfind(vec, 30);
		std::cout << "Valor encontrado no vector: " << *itVec << std::endl;


		// ===== Teste com std::list =====
		std::list<int> lst;
		lst.push_back(100);
		lst.push_back(200);
		lst.push_back(300);

		std::cout << "\n Testando std::list:" << std::endl;
		std::list<int>::iterator itList = easyfind(lst, 200);
		std::cout << "Valor encontrado na list: " << *itList << std::endl;


		// ===== Teste com std::deque =====
		std::deque<int> dq;
		dq.push_back(7);
		dq.push_back(14);
		dq.push_back(21);

		std::cout << "\n Testando std::deque:" << std::endl;
		std::deque<int>::iterator itDeque = easyfind(dq, 14);
		std::cout << "Valor encontrado no deque: " << *itDeque << std::endl;


		// ===== Teste com valor inexistente =====
		std::cout << "\n Testando valor inexistente (vai lançar exceção):" << std::endl;
		easyfind(vec, 99); // este valor não existe
	}
	catch (const std::exception &e)
	{
		std::cerr << " Erro: Valor não encontrado no container!" << std::endl;
	}
	return 0;
}

