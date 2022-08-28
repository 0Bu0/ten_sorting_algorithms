#ifndef _RUN_H_
#define _RUN_H_

#include "sort_algo.h"
#include "test.h"

#ifndef _EXTERN_VALS_
#define _EXTERN_VALS_
extern std::vector<std::string> mp;
extern std::vector<std::vector<int>> test_nums;
#endif

// Run
int Run();

// init
void init_nums_and_run_time();

// cout run time
void cout_run_time();

// cout test case
void cout_test_case();

// cout result
void cout_result();

#endif