/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        traverse(root->left, true, sum);
        traverse(root->right, false, sum);
        return sum;
    }

    void traverse(TreeNode* root, bool isLeft, int &sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
        }
        traverse(root->left, true, sum);
        traverse(root->right, false, sum);
    }
};

int main() {
    Solution s;
    vector<int> preorder({3, 9, 20, 15, 7}), inorder({9, 3, 15, 20, 7});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.sumOfLeftLeaves(root) << endl;

    return 0;
}
