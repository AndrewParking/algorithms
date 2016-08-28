#pragma once


void print_array(int * array, int length);

int * copy_array(int * array, int length);

int * create_random_array(int length);

void selection_sort(int * array, int length);

void quick_sort(int * array, int left, int right, int & qs_counter);

int binary_search(int * array, int length, int const & element);
