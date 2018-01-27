/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given
depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree
nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left
 subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree
 root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of
 the whole original tree, and the original tree is the new root's left subtree.

Example 1:
Input:
A binary tree as following:
       4
     /   \
    2     6
   / \   /
  3   1 5

v = 1

d = 2

Output:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5

Example 2:
Input:
A binary tree as following:
      4
     /
    2
   / \
  3   1

v = 1

d = 3

Output:
      4
     /
    2
   / \
  1   1
 /     \
3       1
Note:
The given d is in range [1, maximum depth of the given tree + 1].
The given binary tree has at least one tree node.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *node = new TreeNode(v);
            node->left = root;
            return node;
        }

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level < d - 1) {
                if (node->left) {
                    q.push(make_pair(node->left, level + 1));
                }
                if (node->right) {
                    q.push(make_pair(node->right, level + 1));
                }
            }
            if (level == d - 1) {
                TreeNode *left = new TreeNode(v);
                TreeNode *right = new TreeNode(v);
                left->left = node->left;
                right->right = node->right;
                node->left = left;
                node->right = right;
            }
        }
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder({4, 2, 3, 1, 6, 5}), inorder({3, 2, 1, 4, 5, 6});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    TreeNode *node = s.addOneRow(root, 1, 2);
    node->print();
    return 0;
}
