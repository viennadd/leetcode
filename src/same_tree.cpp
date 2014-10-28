class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {

        if (p && q)
            return p->val == q->val &&
                    isSameTree(p->left, q->left) &&
                    isSameTree(p->right, q->right);

        if (p == q && p == NULL)
            return true;
        else
            return false;

    }
};