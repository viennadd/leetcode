

#ifndef LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_H

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() == 0)
            return median(nums2);
        if (nums2.size() == 0)
            return median(nums1);

        auto total_size = nums1.size() + nums2.size();
        if (total_size % 2)
        {
            return findKtnElement(nums1, nums2, total_size / 2 + 1);
        }
        else
        {
            return (findKtnElement(nums1, nums2, total_size / 2) +
                    findKtnElement(nums1, nums2, total_size / 2 + 1)) / 2.0;
        }
    }

    double median(vector<int> &v)
    {
        if (v.size() % 2)
        {
            return v.at(v.size() / 2);
        }
        else
        {
            return (v.at(v.size() / 2 - 1) +
                    v.at(v.size() / 2)) / 2.0;
        }
    }


    int& min(int &a, int &b)
    {
        return a < b ? a : b;
    }

    int& findKtnElement(vector<int> &v1, vector<int> &v2, int k)
    {
        auto v1_len = v1.size();
        auto v2_len = v2.size();
        if (v1_len == 0)
            return v2.at(k);
        if (v2_len == 0)
            return v1.at(k);

        if (k == 1)
            return min(v1.at(0), v2.at(0));

        assert(v1_len + v2_len >= k);

        auto v1_begin = v1.begin();
        auto v2_begin = v2.begin();

        while (true) {

            int i, j;
            i = v1_len / (v1_len + v2_len + 0.0) * (k - 1);
            j = k - i - 2;

            auto a = *(v1_begin + i);
            auto b = *(v2_begin + j);
            if (a < b) {
                /* 丢弃 v1 的前 i + 1 (0 base) 个 */
                v1_begin += i + 1;
                v1_len -= i + 1;
                k -= i + 1;
            } else if (b < a) {
                v2_begin += j + 1;
                v2_len -= j + 1;
                k -= j + 1;
            } else {
                /* 相等的话就不用介意了, 随意返回一个都是第 k 小 */
                return *(v1_begin + i);
            }

            if (v1_len == 0)
                return v2.at(k - 1);
            if (v2_len == 0)
                return v1.at(k - 1);

            if (k == 1)
                return min(*v1_begin, *v2_begin);
        }

    }


};

#endif //LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_H
