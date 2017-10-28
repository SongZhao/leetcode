/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w
 as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
 since a node can be a descendant of itself according to the LCA definition.

 */

/*
 * For a binary search tree, left < root < right, so if p, q both < root, then LCA should be in left, if p, q both > root,
 * LCA should be in right
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return root;
        }
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder({6, 2, 0, 4, 3, 5, 8, 7, 9}), inorder({0, 2, 3, 4, 5, 6, 7, 8, 9});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.lowestCommonAncestor(root, root->left, root->right)->val << endl;
    cout << s.lowestCommonAncestor(root, root->left, root->left->right)->val << endl;
    return 0;
}
