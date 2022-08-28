#include "sort_algo.h"

// init map

std::vector<std::string> mp = {
    "bubble_sort",
    "insert_sort",
    "select_sort",
    "quick_sort",
    "merge_sort",
    "heap_sort",
    "bucket_sort",
    "count_sort",
    "radix_sort",
    "shell_sort"};

// swap
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

// solve
void solve(std::vector<int> &nums, methods method)
{
    int len = nums.size();

    // chose algorithm
    switch (method)
    {
    case Bubble_sort:
        bubble_sort(nums);
        break;

    case Insert_sort:
        insert_sort(nums);
        break;

    case Select_sort:
        select_sort(nums);
        break;

    case Quick_sort:
        quick_sort(nums, 0, len - 1);
        break;

    case Merge_sort:
        merge_sort(nums, 0, len - 1);
        break;

    case Heap_sort:
        heap_sort(nums);
        break;

    case Bucket_sort:
        bucket_sort(nums);
        break;

    case Count_sort:
        count_sort(nums);
        break;

    case Radix_sort:
        radix_sort(nums);
        break;

    case Shell_sort:
        shell_sort(nums);
        break;

    default:
        break;
    }

    return;
}

// bubble sort
// time: O(n2)
// space: O(1)
void bubble_sort(std::vector<int> &nums)
{
    int len = nums.size();
    for (int i = 1; i < len; ++i)
    {
        bool done_flag = false; // check if finish

        for (int j = 0; j < len - i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                done_flag = true;
            }
        }

        if (!done_flag)
            break;
    }

    return;
}

// insert sort
// time: O(n2)
// space: O(1)
void insert_sort(std::vector<int> &nums)
{
    int len = nums.size();
    for (int i = 1; i < len; ++i)
        for (int j = i; j > 0 && nums[j - 1] > nums[j]; --j)
            swap(nums[j - 1], nums[j]);

    return;
}

// select sort
// time: O(n2)
// space: O(1)
void select_sort(std::vector<int> &nums)
{
    int len = nums.size();
    int min_number;
    int max_number;
    for (int i = 0; i < len / 2; ++i)
    {
        min_number = i;
        max_number = len - i - 1;
        for (int j = i; j < len - i; ++j)
        {
            if (nums[j] < nums[min_number])
                min_number = j;
            if (nums[j] > nums[max_number])
                max_number = j;
        }

        swap(nums[i], nums[min_number]);
        if (max_number == i)
            swap(nums[min_number], nums[len - i - 1]);
        else
            swap(nums[max_number], nums[len - i - 1]);
    }

    return;
}

// quick sort
// time:
void quick_sort(std::vector<int> &nums, const int left, const int right)
{
    if (left >= right)
        return;

    int pivot = nums[left];
    int first = left;
    int end = right;

    while (first < end)
    {
        // small number -> left
        while (first < end && nums[end] >= pivot)
            --end;
        nums[first] = nums[end];

        // big number -> right
        while (first < end && nums[first] <= pivot)
            ++first;
        nums[end] = nums[first];
    }

    // insert pivot
    nums[first] = pivot;
    quick_sort(nums, left, first - 1);
    quick_sort(nums, first + 1, right);

    return;
}

// merge sort
void merge_sort(std::vector<int> &nums, int left, int right)
{
    // divide
    if (left >= right)
        return;

    int pivot = left + (right - left) / 2;
    merge_sort(nums, left, pivot);
    merge_sort(nums, pivot + 1, right);

    // conquer
    std::vector<int> temp(right - left + 1, 0);
    int len = temp.size();
    int L = left;
    int R = pivot + 1;
    int t = 0;

    while (L <= pivot && R <= right)
    {
        if (nums[L] < nums[R])
            temp[t++] = nums[L++];
        else
            temp[t++] = nums[R++];
    }

    // check the remaining numbers
    while (L <= pivot)
        temp[t++] = nums[L++];
    while (R <= right)
        temp[t++] = nums[R++];

    // copy
    for (int i = 0; i < len; ++i)
        nums[left + i] = temp[i];

    return;
}

// heap sort
void heaplify(std::vector<int> &nums, int len, int max_position)
{
    while (1)
    {
        int i = max_position;
        int child1 = 2 * i + 1;
        int child2 = 2 * i + 2;

        // find max value
        if (child1 < len && nums[max_position] < nums[child1])
            max_position = child1;
        if (child2 < len && nums[max_position] < nums[child2])
            max_position = child2;

        // finish
        if (i == max_position)
            break;

        // adjust max position
        swap(nums[max_position], nums[i]);

        // change next max position we should adjust
        i = max_position;
    }

    return;
}
void heap_sort(std::vector<int> &nums)
{
    int len = nums.size();

    // build heap
    for (int i = len / 2 - 1; i >= 0; --i)
        heaplify(nums, len, i);

    // heap sort
    while (len > 1)
    {
        swap(nums[0], nums[--len]);
        heaplify(nums, len, 0);
    }

    return;
}

// bucket sort
void bucket_sort(std::vector<int> &nums)
{
    int len = nums.size();
    int low = INT_MAX;
    int high = INT_MIN;

    // get bounds
    for (auto x : nums)
    {
        low = low > x ? x : low;
        high = high > x ? high : x;
    }

    // build bucket
    long ln = (long)high - (long)low + 1; // overflow: INT_MAX - INT_MIN
    int bucket_size = ln > 1000 ? 100 : 1;
    ln = ln > 1000 ? ln / 100 : ln;

    int n = (int)ln;
    std::vector<std::vector<int>> bucket(n + 1);
    int bucket_num = 0;
    for (auto x : nums)
    {
        int add_bucket = (int)(((long)x - (long)low) / bucket_size);
        bucket[add_bucket].push_back(x);
    }

    // sort
    for (auto &x : bucket)
        quick_sort(x, 0, x.size() - 1);

    // copy
    int t = 0;
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < bucket[i].size(); ++j)
            nums[t++] = bucket[i][j];

    return;
}

// count sort
void count_sort(std::vector<int> &nums)
{
    int len = nums.size();
    int low = INT_MAX;
    int high = INT_MIN;

    // get bounds
    for (auto x : nums)
    {
        low = low > x ? x : low;
        high = high > x ? high : x;
    }

    // build counts vector
    long n = (long)high - (long)low + 1; // overflow: INT_MAX - INT_MIN
    std::vector<int> counts(n);
    for (auto x : nums)
        ++counts[x - low];

    // copy
    int t = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < counts[i]; ++j)
            nums[t++] = i + low;

    return;
}

// radix sort
void radix_sort(std::vector<int> &nums)
{
    int len = nums.size();

    // check negetive
    std::vector<int> neg_num;
    std::vector<int> nneg_num;
    for (auto x : nums)
    {
        if (x >= 0)
            nneg_num.push_back(x);
        else
            neg_num.push_back(-x);
    }
    if (!neg_num.empty())
    {
        radix_sort(nneg_num);
        radix_sort(neg_num);
        int i = 0;
        int neg_len = neg_num.size();
        for (int j = neg_len - 1; j >= 0; --j)
            nums[i++] = -neg_num[j];
        for (int j = 0; j < nneg_num.size(); ++j)
            nums[i++] = nneg_num[j];

        return;
    }

    // radix: 0 ~ 9
    std::vector<std::vector<int>> rad(10);
    int radix = 1;

    while (1)
    {
        for (int i = 0; i < 10; ++i)
            rad[i].clear();
        for (auto x : nums)
            rad[x / radix % 10].push_back(x);

        radix *= 10;

        int t = 0;
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < rad[i].size(); ++j)
                nums[t++] = rad[i][j];

        // finish
        if (rad[0].size() == len)
            break;
    }

    return;
}

// shell sort
void shell_sort(std::vector<int> &nums)
{
    int len = nums.size();
    for (int gap = len / 2; gap > 0; gap /= 2)
        for (int i = gap; i < len; ++i)
            for (int j = i; j >= gap && nums[j - gap] > nums[j]; j -= gap)
                swap(nums[j], nums[j - gap]);

    return;
}