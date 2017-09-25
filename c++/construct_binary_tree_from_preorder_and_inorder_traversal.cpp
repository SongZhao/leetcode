/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */

/*
 * Similar to 106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }

    TreeNode *build(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
        if (s1 > e1 || s2 > e2) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[s1]);
        int index = -1;
        for (int i = s2; i <= e2; ++i) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return nullptr;
        }
        int leftSize = index - s2;
        root->left = build(preorder, s1 + 1, s1 + leftSize, inorder, s2, index - 1);
        root->right = build(preorder, s1 + leftSize + 1, e1, inorder, index + 1, e2);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 4, 5, 3, 6, 7});
    vector<int> inorder({4, 2, 5, 1, 6, 3, 7});
    TreeNode *root = s.buildTree(preorder, inorder);
    root->print();
    return 0;
}
