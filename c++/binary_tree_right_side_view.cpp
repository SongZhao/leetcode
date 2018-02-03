/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
 ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        traversal(root, res, 1);
        return res;
    }

    void traversal(TreeNode* root, vector<int> &res, int depth) {
        if (!root) {
            return;
        }
        if (res.size() < depth) {
            res.push_back(root->val);
        }
        traversal(root->right, res, depth + 1);
        traversal(root->left, res, depth + 1);
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 5, 3, 4}), inorder({2, 5, 1, 3, 4});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.rightSideView(root) << endl;
    return 0;
}
