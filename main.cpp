#include "src/median_of_two_sorted_arrays.h"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    Solution s;

    vector<int> n1 {1, 2 ,3, 4, 5, 6, 7, 8};
    vector<int> n2 {1, 2, 3, 6};

    cout << s.findMedianSortedArrays(n1, n2) << endl;

    return 0;
}