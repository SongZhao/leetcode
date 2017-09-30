/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
 */

/*
 * INT_MAX and INT_MIN caused some trouble. Use minNode and maxNode instead.
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
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left) && (!root->right)) {
            return true;
        }
        return isValid(root, NULL, NULL);
    }

    bool isValid (TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) {
            return true;
        }
        if ((minNode && root->val <= minNode->val) || (maxNode &&root->val >= maxNode->val)) {
            return false;
        }
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};

int main() {
    Solution s;
    vector<int> preorder({10, 5, 15, 6, 20}), inorder({5, 10, 6, 15, 20});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.isValidBST(root) << endl;
    return 0;
}
