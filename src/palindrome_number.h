//
// Created by vienna on 1/6/2016.
//

#ifndef LEETCODE_PALINDROME_NUMBER_H
#define LEETCODE_PALINDROME_NUMBER_H

#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == INT_MIN || x < 0)
            return false;

        int num = x;
        int result = 0;

        while (num > 0) {
            if ((INT_MAX - num % 10) / 10 < result)
                return false;

            result *= 10;
            result += num % 10;
            num /= 10;
        }

        result = x < 0 ? -result : result;

        return result == x;
    }
};

#endif //LEETCODE_PALINDROME_NUMBER_H
