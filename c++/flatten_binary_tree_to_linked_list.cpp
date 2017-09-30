/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
 */

/*
 * Postorder traversal
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
    TreeNode* pre = NULL;
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3, 4, 5, 6}), inorder({3, 2, 4, 1, 5, 6});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    s.flatten(root);
    root->print();
    return 0;
}
