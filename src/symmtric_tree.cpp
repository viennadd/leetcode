#include <stack>

class Solution {
    std::stack<TreeNode *> left_stack;
    std::stack<TreeNode *> right_stack;
public:
    bool isSymmetric(TreeNode *root) {

        if (!root)
            return true;

        TreeNode *left_root = root->left;
        TreeNode *right_root = root->right;

        while (left_root && right_root || !this->left_stack.empty() && !this->right_stack.empty()) {

            while (left_root && right_root) {
                if (left_root->val != right_root->val)
                    return false;

                left_stack.push(left_root);
                right_stack.push(right_root);
                left_root = left_root->left;
                right_root = right_root->right;

            }

            if (left_root != right_root)
                return false;

            if (!left_stack.empty()) {
                left_root = left_stack.top();
                left_stack.pop();
                left_root = left_root->right;
            }

            if (!right_stack.empty()) {
                right_root = right_stack.top();
                right_stack.pop();
                right_root = right_root->left;
            }
        }

        if (left_root != right_root || left_stack.size() != right_stack.size())
            return false;
        else
            return true;
    }
};