/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
 the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return maxSum;
    }

    int traverse(TreeNode *root) {
        if (!root) {
            return 0;
        }

        int left = max(0, traverse(root->left));
        int right = max(0, traverse(root->right));
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left,right);
    }
};

int main() {
    Solution s;
    vector<int> preorder({3, 4, 1, 2, 5}), inorder({1, 4, 3, 2, 5});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.maxPathSum(root) << endl;
    preorder = {5, 4, 11, 7, 2, 8, 13, 4, 1}, inorder = {7, 11, 2, 4, 5, 13, 8, 4, 1};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.maxPathSum(root) << endl;
    return 0;
}
