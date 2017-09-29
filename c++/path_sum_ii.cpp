/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
 */

/*
 * dfs, similar to "Path Sum", just need a vector to save the path
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        vector<int> cur;
        traverse(root, sum, 0, cur, res);
        return res;
    }

    void traverse(TreeNode* root, int target, int sum, vector<int> cur, vector<vector<int>>& res) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            if (sum + root->val == target) {
                cur.push_back(root->val);
                res.push_back(cur);
            }
        } else {
            cur.push_back(root->val);
            traverse(root->left, target, sum + root->val, cur, res);
            traverse(root->right, target, sum + root->val, cur, res);
        }
    }
};

int main() {
    Solution s;
    int sum = 22;
    vector<int> preorder({5, 4, 11, 7, 2, 8, 13, 4, 5, 1}), inorder({7, 11, 2, 4, 5, 13, 8, 5, 4, 1});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.pathSum(root, sum) << endl;
    preorder = {5, 4, 11, 7, 2, 8, 13, 4, 1}, inorder = {7, 11, 2, 4, 5, 13, 8, 4, 1}, sum = 22;
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.pathSum(root, sum) << endl;
    preorder = {1}, inorder = {1}, sum = 1;
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.pathSum(root, sum) << endl;
    return 0;
}
