//
// Created by vienna on 12/9/2016.
//


#include <vector>
#include <iostream>

using namespace std;

class Solution {

    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int n, int target) {
        vector<int> candidates {1, 2, 3, 4, 5, 6, 7, 8, 9};

        int start_at = 0;
        vector<int> temp;
        helper(candidates, temp, 0, target, n);

        return res;
    }


private:
    void helper(vector<int> &candidates, vector<int> &temp, int start_at, int target, const int &n)
    {
        if (target != 0 && temp.size() >= n)
            return;
        else if (target == 0 && temp.size() == n)
        {
            res.push_back(temp);
        }
        else
        {
            for (int i = start_at; i < candidates.size(); ++i) {

                temp.push_back(candidates[i]);
                helper(candidates, temp, i + 1, target - candidates[i], n);
                temp.pop_back();
            }
        }
    }
};


int main()
{
    Solution s;
    for (auto &v : s.combinationSum3(3, 9)) {
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}