/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
 */

/*
 * simple bfs
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
    int sumNumbers(TreeNode *root) {
        int res = 0;
        if (!root) {
            return 0;
        }
        traverse(root, res, 0);
        return res;
    }

    void traverse(TreeNode *root, int &res, int sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            res += 10 * sum + root->val;
            return;
        }
        sum = 10 * sum + root->val;
        traverse(root->left, res, sum);
        traverse(root->right, res, sum);

    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3}), inorder({2, 1, 3});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.sumNumbers(root) << endl;
    return 0;
}
