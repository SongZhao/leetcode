/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
 */

/*
 * use stack
*/

#include "helper.h"
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            if (tmp->right) {
                s.push(tmp->right);
            }
            if (tmp->left) {
                s.push(tmp->left);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3}), inorder({1, 3, 2});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.preorderTraversal(root) << endl;
    preorder = {3, 1, 2}, inorder = {1, 3, 2};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.preorderTraversal(root) << endl;
    return 0;
}
