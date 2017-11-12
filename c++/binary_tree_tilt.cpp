/*
Given a binary tree, return the tilt of the whole tree.

The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and
 the sum of all right subtree node values. Null node has tilt 0.

The tilt of the whole tree is defined as the sum of all nodes' tilt.

Example:
Input:
         1
       /   \
      2     3
Output: 1
Explanation:
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1
Note:

The sum of node values in any subtree won't exceed the range of 32-bit integer.
All the tilt values won't exceed the range of 32-bit integer.
 */

/*
 * Similar to Diameter of Binary Tree
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
    int tilt = 0;
    int findTilt(TreeNode* root) {
        if (!root) {
            return 0;
        }
        string cur;
        getSum(root);
        return tilt;
    }

    int getSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = getSum(root->left);
        int right = getSum(root->right);
        tilt += abs(left - right);
        return left + right + root->val;
    }
};

int main() {
    Solution s;
    vector<int> preorder({10, 5, 15, 6, 20}), inorder({5, 10, 6, 15, 20});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.findTilt(root) << endl;
    return 0;
}
