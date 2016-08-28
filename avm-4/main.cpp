#include <iostream>
#include "sorting.hpp"


int main()
{
    int length, search_val;
    int qs_counter = 0;

    std::cout << "Enter array length:" << std::endl;
    std::cin >> length;

    int * array = create_random_array(length);
    int * qs_array = copy_array(array, length);
    print_array(array, length);

    selection_sort(array, length);
    print_array(array, length);

    quick_sort(qs_array, 0, length - 1, qs_counter);
    std::cout << "Quick sort took " << qs_counter << " swaps" << std::endl;
    print_array(qs_array, length);

    delete[] array;

    std::cout << "Enter element to search:" << std::endl;
    std::cin >> search_val;

    int search_result = binary_search(qs_array, length, search_val);
    std::cout << "Result: " << search_result << std::endl;

    delete[] qs_array;

    return 0;
}
