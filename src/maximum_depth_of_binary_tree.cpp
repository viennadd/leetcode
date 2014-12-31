#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
private:
	void clear_queue(std::queue<TreeNode *> &src, std::queue<TreeNode *> &dest)
	{
		while (!src.empty()) {
			auto &node = src.front();
			src.pop();

			if (node->left)
				dest.push(node->left);
			if (node->right)
				dest.push(node->right);
		}
	}

public:
	int maxDepth(TreeNode *root) {
		std::queue<TreeNode *> q[2];
		int depth = 0;

		if (!root)
			return 0;

		q[0].push(root);
		for (int i = 0;; ++i) {
			auto &src_queue = q[i & 1];
			auto &dest_queue = q[(i + 1) & 1];

			if (!src_queue.empty()) {
				depth++;
				clear_queue(src_queue, dest_queue);
			}
			else {
				break;
			}
		}

		return depth;
	}
};
