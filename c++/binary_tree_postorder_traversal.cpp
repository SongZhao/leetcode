/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
 */

/*
 * Opposite of preorder. Reverse the results.
*/

#include "helper.h"
#include <algorithm>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> s;
        TreeNode* tmp = root;
        while (tmp || !s.empty()) {
            if(tmp) {
                s.push_back(tmp);
                res.push_back(tmp->val);
                tmp = tmp->right;
            } else {
                tmp = s.back();
                s.pop_back();
                tmp = tmp->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3}), inorder({1, 3, 2});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.postorderTraversal(root) << endl;
    preorder = {1, 2, 4, 5, 3, 6, 7}, inorder = {4, 2, 5, 1, 6, 3, 7};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.postorderTraversal(root) << endl;
    return 0;
}
