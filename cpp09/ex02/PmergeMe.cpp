#include "PmergeMe.hpp"

/* CONSTRUCTORS */
PmergeMe::PmergeMe(void)
    : numbers_vec(), numbers_deq(), movement_count_vec(0), movement_count_deq(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

/* DESTRUCTOR */
PmergeMe::~PmergeMe(void) {}

/* OPERATOR */
PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->numbers_vec = other.numbers_vec;
        this->numbers_deq = other.numbers_deq;
    }
    return *this;
}

/* INPUT PARSING */
void PmergeMe::parseInput(int ac, char **av) {

    if (ac <= 1)
        throw std::invalid_argument("missing argument");

    std::set<int> check_duplicates;

    for (int i = 1; i < ac; i++) {

        std::string arg(av[i]);

        if (arg.empty())
            throw std::invalid_argument("empty input");

        if (arg[0] == '-')
            throw std::invalid_argument("negative value not allowed");

        if (arg[0] == '+')
            throw std::invalid_argument("unsigned values only");

        for (size_t j = 0; j < arg.size(); j++) {
            if (isspace(arg[j]))
                throw std::invalid_argument("each value must be a separate argument");
            if (!isdigit(arg[j]))
                throw std::invalid_argument("value is not a digit");
        }

        std::istringstream iss(arg);
        int num;
        iss >> num;

        if (check_duplicates.find(num) != check_duplicates.end())
            throw std::invalid_argument("duplicate values not allowed");

        check_duplicates.insert(num);

        numbers_vec.push_back(num);
        numbers_deq.push_back(num);
    }
}

/* MAIN SORTER */
void PmergeMe::sort(void) {

    std::clock_t start_deque = std::clock();
    sortDeque();
    std::clock_t end_deque = std::clock();
    
    std::cout << "Before              :  ";
    printContainer(numbers_vec);

    std::clock_t start_vector = std::clock();
    sortVector();
    std::clock_t end_vector = std::clock();

    std::cout << "After (std::vector) :  ";
    printContainer(numbers_vec);

    std::cout << "After (std::deque)  :  ";
    printContainer(numbers_deq);

    // Time for vector
    double duration = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << numbers_vec.size()
        << " elements with std::vector : " << std::fixed << std::setprecision(7)
        << duration << " seconds" << std::endl;

    // Time for deque
    duration = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << numbers_deq.size()
        << " elements with std::deque  : " << std::fixed << std::setprecision(7)
        << duration << " seconds" << std::endl;
}

/* VECTOR SORT */
void PmergeMe::sortVector(void) {
    if (numbers_vec.size() > 1)
        numbers_vec = mergeInsertionVec(numbers_vec);
}

/* DEQUE SORT */
void PmergeMe::sortDeque(void) {
    if (numbers_deq.size() > 1)
        numbers_deq = mergeInsertionDeq(numbers_deq);
}

/* MERGE-INSERTION SORT FOR VECTOR */
std::vector<int> PmergeMe::mergeInsertionVec(std::vector<int> vec) {

    std::vector<int> main;
    std::vector<int> other;

    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.end();

    while (start + 1 < end) {
        if (*start < *(start + 1)) {
            other.push_back(*start);
            main.push_back(*(start + 1));
        }
        else {
            other.push_back(*(start + 1));
            main.push_back(*start);
        }
        start += 2;
    }

    if (start != end)
        other.push_back(*start);

    if (vec.size() <= 1)
        return vec;

    main = mergeInsertionVec(main);

    std::vector<int> jacob_insertion_order = getInsertionOrderVec(other.size());
    int counter = 0;

    for (size_t i = 0; i < jacob_insertion_order.size(); i++) {

        int idx = jacob_insertion_order[i];
        int value = other[idx];

        int low = 0;
        int high = main.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (main[mid] == value) {
                main.insert(main.begin() + mid, value);
                counter++;
                break;
            }
            if (main[mid] < value)
                low = mid + 1;
            else
                high = mid - 1;

            counter++;
        }
        main.insert(main.begin() + low, value);
    }

    movement_count_vec = counter;
    return main;
}

/* JACOBSTHAL INSERTION ORDER FOR VECTOR */
std::vector<int> PmergeMe::getInsertionOrderVec(size_t size) {

    std::vector<int> sequence;
    std::vector<bool> tracker(size, false);

    std::vector<int> jacobsthal = getJacobsthal<std::vector<int> >(size);

    for (size_t i = 0; i < jacobsthal.size(); i++) {
        int n = jacobsthal[i] - 1;
        sequence.push_back(n);
        tracker[n] = true;
    }

    for (size_t i = 0; i < size; i++) {
        if (!tracker[i]) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}

/* MERGE-INSERTION SORT FOR DEQUE */
std::deque<int> PmergeMe::mergeInsertionDeq(std::deque<int> deq) {

    std::deque<int> main;
    std::deque<int> other;

    std::deque<int>::iterator start = deq.begin();
    std::deque<int>::iterator end = deq.end();

    while (start + 1 < end) {
        if (*start < *(start + 1)) {
            other.push_back(*start);
            main.push_back(*(start + 1));
        }
        else {
            other.push_back(*(start + 1));
            main.push_back(*start);
        }
        start += 2;
    }

    if (start != end)
        other.push_back(*start);

    if (deq.size() <= 1)
        return deq;

    main = mergeInsertionDeq(main);

    std::deque<int> jacob_insertion_order = getInsertionOrderDeq(other.size());
    int counter = 0;

    for (size_t i = 0; i < jacob_insertion_order.size(); i++) {

        int idx = jacob_insertion_order[i];
        int value = other[idx];

        int low = 0;
        int high = main.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (main[mid] == value) {
                main.insert(main.begin() + mid, value);
                counter++;
                break;
            }
            if (main[mid] < value)
                low = mid + 1;
            else
                high = mid - 1;

            counter++;
        }
        main.insert(main.begin() + low, value);
    }

    movement_count_deq = counter;
    return main;
}

/* JACOBSTHAL INSERTION ORDER FOR DEQUE */
std::deque<int> PmergeMe::getInsertionOrderDeq(size_t size) {

    std::deque<int> sequence;
    std::deque<bool> tracker(size, false);

    std::deque<int> jacobsthal = getJacobsthal<std::deque<int> >(size);

    for (size_t i = 0; i < jacobsthal.size(); i++) {
        int n = jacobsthal[i] - 1;
        sequence.push_back(n);
        tracker[n] = true;
    }

    for (size_t i = 0; i < size; i++) {
        if (!tracker[i]) {
            sequence.push_back(i);
            tracker[i] = true;
        }
    }
    return sequence;
}