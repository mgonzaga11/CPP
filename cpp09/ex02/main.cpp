#include "PmergeMe.hpp"

int main(int ac, char **av) {
    try {
        PmergeMe sorter;
        sorter.parseInput(ac, av);
        sorter.sort();
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}