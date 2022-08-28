#include "run.h"

// variable
std::vector<std::vector<int>> nums;
std::vector<clock_t> run_time;

// function
// Run
int Run()
{
    // add rand nums
    add_rand_nums();

    // sort
    int nums_len = test_nums.size();
    clock_t start, end;
    methods method;

    for (int i = 0; i < nums_len; ++i)
    {
        // copy
        init_nums_and_run_time();
        for (int j = 0; j < SORT_ALGO_NUM; ++j)
            nums.push_back(test_nums[i]);

        // solve
        for (int j = 0; j < SORT_ALGO_NUM; ++j)
        {
            method = (enum methods)j;

            start = clock();
            solve(nums[j], method);
            end = clock();
            run_time[j] = end - start;

            std::cout << mp[j] << "\tdone!\n";
        }

        // cout test case and result
        if (test_nums[i].size() <= MAX_COUT_LEN)
        {
            cout_test_case();
            cout_result();
        }

        // cout run time
        cout_run_time();
    }

    return 0;
}

// init
void init_nums_and_run_time()
{
    nums.clear();
    run_time.clear();
    run_time.resize(SORT_ALGO_NUM);

    return;
}

// cout run time
void cout_run_time()
{
    std::vector<bool> correct = Check(nums);
    std::cout << "\n----RUN TIME----\n";
    for (int j = 0; j < SORT_ALGO_NUM; ++j)
        std::cout << mp[j] << "\t\t" << run_time[j] << "\t\t\t" << (correct[j] ? "TRUE" : "FALSE") << std::endl;
    std::cout << std::endl;

    return;
}

// cout test case
void cout_test_case()
{
    std::cout << "\ntest case:";
    Cout(nums[0]);
    std::cout << "\n";

    return;
}

// cout result
void cout_result()
{
    for (int i = 0; i < SORT_ALGO_NUM; ++i)
    {
        std::cout << mp[i];
        Cout(nums[i]);
        std::cout << std::endl;
    }

    return;
}