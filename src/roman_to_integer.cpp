#include <stack>
#include <map>
#include <string>

class Solution {
    std::map<int, int> units;
public:
    Solution() {
        units['I'] = 1;
        units['V'] = 5;
        units['X'] = 10;
        units['L'] = 50;
        units['C'] = 100;
        units['D'] = 500;
        units['M'] = 1000;
    }

    int romanToInt(std::string s) {
        std::stack<char> chars;
        const char *ptr = s.c_str();

        int value = 0;
        int top_value = 0;

        chars.push(*ptr);

        ptr++;
        while (*ptr) {

            chars.push(*ptr);

            if (*(ptr + 1) && !chars.empty() &&
                    units.find(*(ptr + 1))->second < units.find(chars.top())->second) {

                top_value = units.find(chars.top())->second;
                while (!chars.empty()) {
                    if (units.find(chars.top())->second < top_value)
                        value -= units.find(chars.top())->second;
                    else
                        value += units.find(chars.top())->second;
                    chars.pop();
                }
            }

            ptr++;
        }

        top_value = units.find(chars.top())->second;
        while (!chars.empty()) {
            if (units.find(chars.top())->second < top_value)
                value -= units.find(chars.top())->second;
            else
                value += units.find(chars.top())->second;
            chars.pop();
        }

        return value;
    }
};

int main()
{
    Solution sol;
    std::string s("MMCDXXXIV");
    std::cout << sol.romanToInt(s) << std::endl;
}