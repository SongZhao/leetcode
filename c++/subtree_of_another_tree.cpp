/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with
 a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could
 also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return s && (isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));

    }

    bool isEqual(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }
        return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

};

int main() {
    Solution s;
    vector<int> preorder({3, 4, 1, 2, 5}), inorder({1, 4, 2, 3, 5});
    TreeNode *st = buildTree(preorder, inorder);
    st->print();
    preorder = {4, 1, 2};
    inorder = {1, 4, 2};
    TreeNode *tt = buildTree(preorder, inorder);
    tt->print();
    cout << s.isSubtree(st, tt);

    preorder = {3, 1, 4, 2, 0, 5};
    inorder = {1, 4, 0, 2, 3, 5};
    st = buildTree(preorder, inorder);
    st->print();
    cout << s.isSubtree(st, tt);

    return 0;
}
