/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> s;
        TreeNode* tmp = root;
        while (tmp || !s.empty()) {
            while(tmp) {
                s.push_back(tmp);
                tmp = tmp->left;
            }
            if (!s.empty()) {
                tmp = s.back();
                s.pop_back();
                res.push_back(tmp->val);
                tmp = tmp->right;
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
    cout << s.inorderTraversal(root) << endl;
    preorder = {1, 2, 4, 5, 3, 6, 7}, inorder = {4, 2, 5, 1, 6, 3, 7};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.inorderTraversal(root) << endl;
    return 0;
}
