//
// Created by vienna on 9/9/2016.
//

/*
 * house robber II 把数据变成环形, 思路是首尾不能相邻, 那结果会是两种情况之一:
 * 不包含首元素的答案、不包含尾元素的答案, 其中较大者
 *
 * */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp {0, 0};

        for (auto &i : nums) {
            int x = max(dp.back(), dp[dp.size() - 2] + i);
            dp.push_back(x);

            cout << x << endl;
        }



        return dp.back();
    }
};

int main()
{
    vector<int> nums {400, 5, 90, 500};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}