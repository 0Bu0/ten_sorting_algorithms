#ifndef _TEST_H_
#define _TEST_H_

#include <stdlib.h> //rand
#include <ctime>    //clock time
#include <vector>
#include <iostream>

#define RAND_ADD_NUM 5
#define RAND_ADD_MAX 5000
#define RAND_ADD_MIN -5000
#define RAND_ADD_LEN 10000
#define MAX_COUT_LEN 30

// add rand numbers
void add_rand_nums();

// Cout
void Cout(std::vector<int> &nums);

// check
std::vector<bool> Check(std::vector<std::vector<int>> &nums);

#endif