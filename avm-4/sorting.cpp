#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.hpp"


void print_array(int * array, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


int * copy_array(int * array, int length)
{
    int * new_array = new int[length];

    for (int i = 0; i < length; ++i) new_array[i] = array[i];

    return new_array;
}


int * create_random_array(int length)
{
    int * array = new int[length];

    srand(time(NULL));

    for (int i = 0; i < length; ++i)
    {
        array[i] = rand() % 100;
    }

    return array;
}


void selection_sort(int * array, int length)
{
    int min, k, tmp, counter = 0;

    for (int i = 0; i < length - 1; ++i)
    {
        min = array[i];
        k = i;

        for (int j = i + 1; j < length; ++j)
        {
            if (array[j] < min)
            {
                min = array[j];
                k = j;
            }
        }

        if (k != i)
        {
            tmp = array[k];
            array[k] = array[i];
            array[i] = tmp;
            counter++;
        }
    }

    std::cout << "Sorting took " << counter << " swaps" << std::endl;
}


void quick_sort(int * array, int left, int right, int & qs_counter)
{
    int tmp;
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];

    do
    {
        while (array[i] < pivot) ++i;
        while (array[j] > pivot) --j;

        if (i <= j)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            ++i;
            --j;
            ++qs_counter;
        }
    } while(i <= j);

    if (left < j) quick_sort(array, left, j, qs_counter);
    if (i < right) quick_sort(array, i, right, qs_counter);
}


int binary_search(int * array, int length, int const & element)
{
    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        int check_index = (start + end) / 2;

        if (element < array[check_index])
        {
            end = check_index - 1;
        }
        else if (element > array[check_index])
        {
            start = check_index + 1;
        }
        else
        {
            return check_index;
        }
    }

    return -1;
}
