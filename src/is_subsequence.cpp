//
// Created by vienna on 21/9/2016.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto sit = s.begin();
        auto tit = t.begin();

        while (sit != s.end() && tit != t.end()) {
            if (*sit == *tit) {
                sit++;
                tit++;
            } else {
                tit++;
            }
        }

        if (sit == s.end())
            return true;

        return false;
    }
};


int main()
{
    Solution s;

    cout << s.isSubsequence("", "ahbgdc") << endl;
    return 0;
}