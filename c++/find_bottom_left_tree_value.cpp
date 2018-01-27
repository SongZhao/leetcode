/*
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.

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
    int findBottomLeftValue(TreeNode* root) {
        int res, maxLevel = 0;
        dfs(root, 1, maxLevel, res);

        return res;
    }

    void dfs(TreeNode *root, int level, int &maxLevel, int &res) {
        if (!root) {
            return;
        }
        if (level > maxLevel) {
            res = root->val;
            maxLevel = level;
        }
        dfs(root->left, level + 1, maxLevel, res);
        dfs(root->right, level + 1, maxLevel, res);
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 4, 3, 5, 7, 6}), inorder({4, 2, 1, 7, 5, 3, 6});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.findBottomLeftValue(root) << endl;

    return 0;
}
