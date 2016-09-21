//
// Created by vienna on 1/6/2016.
//

#ifndef LEETCODE_REVERSE_INTEGER_H
#define LEETCODE_REVERSE_INTEGER_H
#include <climits>

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;

        int num = x < 0 ? -x : x;
        int result = 0;

        while (num > 0) {
            if ((INT_MAX - num % 10) / 10 < result)
                return 0;

            result *= 10;
            result += num % 10;
            num /= 10;
        }

        result = x < 0 ? -result : result;

        return result;
    }
};

#endif //LEETCODE_REVERSE_INTEGER_H
