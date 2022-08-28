#ifndef _SORT_ALGO_H_
#define _SORT_ALGO_H_

#include <vector>
#include <string>
#include <iostream>

#define SORT_ALGO_NUM 10

//____enum____

enum methods
{
    Bubble_sort,
    Insert_sort,
    Select_sort,
    Quick_sort,
    Merge_sort,
    Heap_sort,
    Bucket_sort,
    Count_sort,
    Radix_sort,
    Shell_sort
};

//____function____
// swap
void swap(int &a, int &b);

// solve
void solve(std::vector<int> &nums, methods method);

// sort algorithm
// bubble sort
void bubble_sort(std::vector<int> &nums);

// insert sort
void insert_sort(std::vector<int> &nums);

// select sort
void select_sort(std::vector<int> &nums);

// quick sort
void quick_sort(std::vector<int> &nums, const int left, const int right);

// merge sort
void merge_sort(std::vector<int> &nums, int left, int right);

// heap sort
void heaplify(std::vector<int> &nums, int left, int right);
void heap_sort(std::vector<int> &nums);

// bucket sort
void bucket_sort(std::vector<int> &nums);

// count sort
void count_sort(std::vector<int> &nums);

// radix sort
void radix_sort(std::vector<int> &nums);

// shell sort
void shell_sort(std::vector<int> &nums);

#endif