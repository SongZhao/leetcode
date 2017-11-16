/*
Given a binary tree, find the length of the longest path where each node in the path has the same value.
 This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int res = 0;

    int longestUnivaluePath(TreeNode *root) {
        traverse(root);
        return res;
    }

    int traverse(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if (root->left && root->left->val == root->val) {
            arrowLeft += left + 1;
        }
        if (root->right && root->right->val == root->val) {
            arrowRight += right + 1;
        }
        res = max(res, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }

};

int main() {
    Solution s;
    vector<int> preorder({5, 4, 1, 5, 5, 5}), inorder({1, 4, 1, 5, 5, 5});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.longestUnivaluePath(root) << endl;
    return 0;
}
