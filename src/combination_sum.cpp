//
// Created by vienna on 11/9/2016.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {

    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        candidates.erase(
                remove_if(candidates.begin(), candidates.end(),
                          [&target](int &x) { return x > target; }),
                candidates.end());


        sort(candidates.begin(), candidates.end());

        int start_at = 0;
        vector<int> temp;
        helper(candidates, temp, 0, target);

        return res;
    }


private:
    void helper(vector<int> &candidates, vector<int> &temp, int start_at, int target)
    {
        if (target < 0)
            return;
        else if (target == 0)
        {
            res.push_back(temp);
        }
        else
        {
            for (int i = start_at; i < candidates.size(); ++i) {

                temp.push_back(candidates[i]);
                helper(candidates, temp, i + 1, target - candidates[i]);
                temp.pop_back();

                while (i < candidates.size() - 1 &&
                        candidates[i] == candidates[i + 1])
                    i++;
            }
        }
    }
};


int main()
{
    Solution s;
    vector<int> candidates {10,1,2,7,6,1,5};
    for (auto &v : s.combinationSum(candidates, 8)) {
        for (auto &e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}