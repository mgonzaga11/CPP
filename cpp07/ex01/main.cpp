
#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::string strArr[] = {"ola", "mundo", "iter"};
    const int constArr[] = {10, 20, 30};

    std::cout << "Array de int:" << std::endl;
    iter(arr, 5, printArray);

    std::cout << "\nArray de string:" << std::endl;
    iter(strArr, 3, printArray);

    std::cout << "\nArray const int:" << std::endl;
    iter(constArr, 3, printArray);

    return 0;
}