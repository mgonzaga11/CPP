#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Topo: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Tamanho: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\nIterando:\n";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}