#include <vector>
#include <algorithm>
using namespace std;

/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

All posible subset will found at:
	n numbers, every number have only 2 states(show and no show)
	so, total 2^n different subset can be enumerate by using n numbers

Binary Subset Enumeration
	this method emulate the show and no show in binary 1 and 0
	print out all value that the position is 1 
*/

class Solution {
private:

public:
	vector<vector<int> > subsets(vector<int> &S) {
		int nElement = S.size();

		sort(S.begin(), S.end());

		vector<vector<int>> result;

		/* empty set */
		result.push_back(vector<int>());

		for (int s = 0; s < 1 << nElement; ++s) {
			vector<int> v = vector<int>();

			for (int i = 0; i < nElement; ++i) {
				
				if (s & (1 << i))
					v.push_back(S.at(i));
			}
			
			if (v.size())
				result.push_back(v);
		}

		return result;
	}
};
