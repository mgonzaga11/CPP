#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <cctype>

class PmergeMe {
private:
    std::vector<int> numbers_vec;
    std::deque<int> numbers_deq;

    int movement_count_vec;
    int movement_count_deq;

public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe(void);

    PmergeMe &operator=(const PmergeMe &other);

    void parseInput(int ac, char **av);
    void sort(void);

private:
    // sorting
    void sortVector(void);
    void sortDeque(void);

    std::vector<int> mergeInsertionVec(std::vector<int> vec);
    std::deque<int>  mergeInsertionDeq(std::deque<int> deq);

    // insertion order
    std::vector<int> getInsertionOrderVec(size_t size);
    std::deque<int>  getInsertionOrderDeq(size_t size);

    // jacobsthal (template)
    template <typename Container>
    Container getJacobsthal(size_t n) {
        Container jac;
        if (n == 0) return jac;

        size_t j1 = 1, j2 = 1;
        while (j2 <= n) {
            jac.push_back(j2);
            size_t tmp = j2;
            j2 = j2 + 2 * j1;
            j1 = tmp;
        }
        return jac;
    }

    // printing
    template <typename Container>
    void printContainer(const Container &c) const {
        for (size_t i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;
    }
};

#endif