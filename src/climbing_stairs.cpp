//
// Created by vienna on 9/9/2016.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {

    vector<int> cache;

public:

    Solution () : cache {1, 1}
    {

    }

    int climbStairs(int n) {

        int c = n - cache.size() + 1;

        if (c > 0)
            for (int i = 0; i < c; ++i) {
                int t = cache.back() + cache[cache.size() - 2];
                cache.push_back(t);
            }

        return cache[n];
    }
};


int main()
{
    Solution s;
    cout << s.climbStairs(5) << endl;
    return 0;
}