#include <string>
#include <stack>
using namespace std;

class Solution {
private:
	bool check_stack_top(stack<char> &stack, char c)
	{
		if (stack.empty())
			return false;

		char t = stack.top();
		stack.pop();

		int diff = c - t;

		return diff <= 2;
	}

public:
	bool isValid(string s) {
		const char *squence = s.c_str();
		stack<char> stack;

		for (int i = 0; i < s.length(); ++i) {
			if (squence[i] == '{' ||
				squence[i] == '[' ||
				squence[i] == '(')
			{
				stack.push(squence[i]);
			}
			else {

				if (!check_stack_top(stack, squence[i]))
					return false;
			}
		}
		return stack.empty();
	}
};
