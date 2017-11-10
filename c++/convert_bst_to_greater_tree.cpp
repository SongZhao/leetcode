/*
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to
 the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
 */

/*
 * reverse inorder traversal
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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }

    void traverse(TreeNode *root) {
        if (!root) {
            return;
        }
        traverse(root->right);
        root->val += sum;
        sum = root->val;
        traverse(root->left);

    }
};

int main() {
    Solution s;
    vector<int> preorder({5, 2, 13}), inorder({2, 5, 13});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    s.convertBST(root);
    root->print();
    return 0;
}
