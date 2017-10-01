/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        if (!root) {
            return res;
        }
        string cur;
        traverse(root, res, cur);
        return res;
    }

    void traverse(TreeNode *root, vector<string> &res, string cur) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            cur += std::to_string(root->val);
            res.push_back(cur);
            return;
        }
        cur += std::to_string(root->val) + "->";
        traverse(root->left, res, cur);
        traverse(root->right, res, cur);

    }
};

int main() {
    Solution s;
    vector<int> preorder({10, 5, 15, 6, 20}), inorder({5, 10, 6, 15, 20});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.binaryTreePaths(root) << endl;
    return 0;
}
