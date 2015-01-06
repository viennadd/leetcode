#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {

		if (strs.size() == 0)
			return string();

		int min_length = strs.begin()->size();
		for (auto i = strs.begin(); i != strs.end(); ++i)
			if (i->size() < min_length)
				min_length = i->size();

		int longest = 0;

		for (int i = 0; i < min_length; ++i) {
			auto s = strs.begin();
			char c = s->c_str()[i];

			for (; s != strs.end(); ++s) {
				if (c != s->c_str()[i])
					return s->substr(0, longest);
			}

			longest++;
		}

		return strs.begin()->substr(0, longest);
	}
};


