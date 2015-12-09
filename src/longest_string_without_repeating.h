//
// Created by vienna on 8/12/2015.
//

#ifndef LEETCODE_LONGEST_STRING_WITHOUT_REPEATING_H
#define LEETCODE_LONGEST_STRING_WITHOUT_REPEATING_H

#include <string>
#include <algorithm>

using namespace std;


class Solution {
private:
    const int NOT_MET_BEFORE = -10;

public:
    int lengthOfLongestSubstring(string s) {

        // two pointer traversal
        const char *p = s.c_str();
        const char *a = p;

        // buffer keep the index of character met.
        int *buffer = new int[128];
        int max = 0, length = 0;

        fill(buffer, buffer + 128, NOT_MET_BEFORE);

        for (int i = 0; i < s.length(); ++i) {

            if (buffer[p[i]] == NOT_MET_BEFORE) {

                buffer[p[i]] = i;
                length++;

            } else {

                /*
                 * get max
                 * moving a to first MET + 1, and clear all in it's left hand side to NOT MET
                 * set starting point of length to a
                 */

                max = length > max ? length : max;

                // clear up to the first met
                // buffer[p[i]] = index MET BEFORE = buffer['x']
                int destination = buffer[p[i]] + 1;
                while ((a - p) < destination) {
                    buffer[*a++] = NOT_MET_BEFORE;
                }

                length = (p + i) - a;

                buffer[p[i]] = i;
                length++;
            }

        }

        return length > max ? length : max;
    }
};

#endif //LEETCODE_LONGEST_STRING_WITHOUT_REPEATING_H
