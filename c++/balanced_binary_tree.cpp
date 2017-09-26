/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */

/*
 * dfs
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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) {
            return -1;
        }
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3}), inorder({1, 2, 3});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.isBalanced(root) << endl;
    return 0;
}
