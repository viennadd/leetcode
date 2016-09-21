//
// Created by vienna on 9/9/2016.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;

        int min = prices[0];
        int maxProfit = 0;

        for (auto &p : prices) {
            if (p < min)
                min = p;

            if (p - min > maxProfit)
                maxProfit = p - min;
        }

        return maxProfit;
    }
};

int main()
{
    vector<int> prices {7, 1, 5, 3, 6, 4};

    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}