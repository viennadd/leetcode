
#include <vector>
#include <map>
#include <iostream>
using  namespace std;

/**
 *
 * brute force is slow.
 *
 * if two number only, using HASHMAP to find towSum
 *
 * num + b = target
 *
 * using num as key, keep index as value
 *
 * if map[b] found a previous value that means
 *      we find num + b = target
 *
 * for K-sum question which K > 2, sort first is more effective than brute force searching.
 *
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int b = 0;

        map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {

            b = target - nums[i];

            auto it = m.find(b);

            if (it != m.end()) {
                return {it->second + 1, i + 1};
            } else {
                m[nums[i]] = i;
            }

        }

        return {};
    }
};