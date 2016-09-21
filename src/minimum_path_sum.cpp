//
// Created by vienna on 21/9/2016.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        // just override grid for dp caching
        for (int i = 1; i < grid[0].size(); ++i) {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid.back().back();

    }
};


int main()
{

    return 0;
}