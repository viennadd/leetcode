
/*
https://oj.leetcode.com/problems/first-missing-positive/
Given an unsorted integer array, find the first missing positive integer.

For example,
Given[1, 2, 0] return 3,
and[3, 4, -1, 1] return 2.

Your algorithm should run in O(n) time and uses constant space.

////////////////////////////////////////////////////

First scanning
Drop negative number and numbers bigger than n, swap remainings into their position.

Second scanning
Find the first missing positive.

*/

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; ++i) {
			bool valid_number = true;
			bool valid_position = false;

			while (valid_number && !valid_position) {
				if (A[i] <= 0 || A[i] > n) {
					valid_number = false;
					continue;
				}

				if (A[i] - 1 != i) {
					if (A[i] == A[A[i] - 1])	/* if currnent == target, don't swap and overwrite current */
						A[i] = -1;
					else
						swap(A, i, A[i] - 1);
				}
				else {
					valid_position = true;
				}
			}
		}

		int i = 0;
		for (; i < n; ++i) {
			if (A[i] <= 0 || A[i] > n)
				return i + 1;
		}

		return i + 1;
	}

	void swap(int A[], int a, int b) {

		int t = A[a];
		A[a] = A[b];
		A[b] = t;
	}
};
