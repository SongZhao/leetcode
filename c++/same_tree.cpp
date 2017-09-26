/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

/*
 * Simple dfs
*/

#include "helper.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3, 4, 2, 4, 3}), inorder({3, 2, 4, 1, 4, 2, 3});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    preorder = {1, 2, 3, 4, 2, 4, 3}, inorder = {3, 2, 4, 1, 4, 2, 3};
    TreeNode *root1 = buildTree(preorder, inorder);
    cout << s.isSameTree(root, root1) << endl;
    return 0;
}
