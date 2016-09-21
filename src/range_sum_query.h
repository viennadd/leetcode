#ifndef RANGE_SUM_QUERY_H
#define RANGE_SUM_QUERY_H

#include <vector>

using namespace std;

class NumArray {
    vector<int> dp;
    const vector<int> &nums;
public:
    NumArray(vector<int> &nums) : nums{nums}  {
        dp.push_back(0); // init

        for (auto &x : nums) {
            dp.push_back(dp.back() + x);
        }
    }

    int sumRange(int i, int j) {
        if (i == j)
            return nums[j];
        else
            return dp[j + 1] - dp[i];
    }
};


#endif