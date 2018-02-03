/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 */

/*
 *
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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = new TreeNode(INT_MIN);

    void recoverTree(TreeNode *root) {
        dfs(root);
        swap(first->val, second->val);

    }

    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        dfs(root->left);

        if (!first && root->val <= pre->val) {
            first = pre;
        }
        if (first && root->val <= pre->val) {
            second = root;
        }
        pre = root;
        dfs(root->right);
    }
};

int main() {
    Solution s;
    vector<int> preorder({3, 4, 1, 2, 5}), inorder({1, 4, 3, 2, 5});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    s.recoverTree(root);
    root->print();

    preorder = {0, 1}, inorder = {1, 0};
    root = buildTree(preorder, inorder);
    root->print();
    s.recoverTree(root);
    root->print();

    return 0;
}
