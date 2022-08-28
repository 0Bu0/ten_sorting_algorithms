#include "test.h"

std::vector<std::vector<int>> test_nums{
    {},
    {1},
    {1, 1},
    {1, 2},
    {1, 1, 1, 1, 1, 1},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
    {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 1315, 665, -5, 15135, -35, 13, 13, 1, 51, -66, 56, 5, 15, 498, 89, 84, 5, -53, 45, 486, 48, 9, 894, -8, 44, 46, 46}};

// function
// add rand numbers
void add_rand_nums()
{
    srand((unsigned)time(0));
    for (int i = 0; i < RAND_ADD_NUM; ++i)
    {
        std::vector<int> add_nums;

        for (int j = 0; j < RAND_ADD_LEN; ++j)
            add_nums.push_back(rand() % (RAND_ADD_MAX - RAND_ADD_MIN + 1) + RAND_ADD_MIN);

        test_nums.push_back(add_nums);
    }

    return;
}

// Cout
void Cout(std::vector<int> &nums)
{
    std::cout << "\t";
    for (auto x : nums)
        std::cout << x << " ";
    return;
}

// check
std::vector<bool> Check(std::vector<std::vector<int>> &nums)
{
    std::vector<bool> res;
    res.push_back(true);
    int len = nums[0].size();

    for (int i = 1; i < 10; ++i)
    {
        bool flag = true;
        for (int j = 0; j < len; ++j)
        {
            if (nums[i][j] != nums[0][j])
            {
                flag = false;
                break;
            }
        }
        res.push_back(flag);
    }
    return res;
}