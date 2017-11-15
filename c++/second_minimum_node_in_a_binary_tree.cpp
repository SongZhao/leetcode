/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has
 exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input:
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
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

    int min = -1, secondMin = -1;

    int findSecondMinimumValue(TreeNode *root) {
        traverse(root);
        return secondMin;
    }

    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        if (root->val < min || min == -1) {
            secondMin = min;
            min = root->val;
        } else if ((root->val < secondMin || secondMin == -1) && root->val != min) {
            secondMin = root->val;
        }
        traverse(root->left);
        traverse(root->right);
    }
};

int main() {
    Solution s;
    vector<int> preorder, inorder;
    TreeNode *root;

    preorder = {INT_MAX - 1, INT_MAX, INT_MAX};
    inorder = {INT_MAX, INT_MAX - 1, INT_MAX};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.findSecondMinimumValue(root) << endl;

    return 0;
}
