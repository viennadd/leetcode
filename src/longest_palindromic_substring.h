

#ifndef LEETCODE_LONGEST_PALINDROMIC_SUBSTRING_H
#define LEETCODE_LONGEST_PALINDROMIC_SUBSTRING_H

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/* maximum size is 1000 */
static int dp[1010][1010];

class Solution {

public:
    string longestPalindrome(string s) {

        string s2 = string(s.rbegin(), s.rend());

        auto s_len = s.size();

        /* base cases */
        for (int i = 0; i < s_len; ++i)
        {
            dp[0][i] = dp[i][0] = 0;
        }

        int longest_end = 0, longest_size = 0;
        longest_common_substring(s, s2, longest_end, longest_size);


        return string(s.begin() + longest_end + 1 - longest_size, s.begin() + longest_end + 1);
    }

    /* len(s1) == len(s2) */
    void longest_common_substring(const string &s1, const string &s2, int &longest_end, int &longest_size)
    {
        auto s_len = s1.size();

        for (int i = 0; i < s_len; ++i)
        {
            for (int j = 0; j < s_len; ++j)
            {
                if (s1[i] == s2[j])
                {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if (dp[i + 1][j + 1] > longest_size)
                    {
                        longest_size = dp[i + 1][j + 1];
                        longest_end = i;
                    }

                }
                else
                {
                    dp[i + 1][j + 1] = 0;
                }
            }
        }

    }
};

#endif //LEETCODE_LONGEST_PALINDROMIC_SUBSTRING_H
