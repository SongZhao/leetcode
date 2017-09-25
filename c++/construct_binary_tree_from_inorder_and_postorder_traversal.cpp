/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */

/*
 * The last element of postorder is always root. left and right part is inorder split by root.
 * Split and recursively set left and right.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    }

    TreeNode *build(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2) {
        if (s1 > e1 || s2 > e2) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[e2]);
        int index = -1;
        for (int i = s1; i <= e1; ++i) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return nullptr;
        }
        int leftSize = index - s1;
        root->left = build(inorder, s1, index - 1, postorder, s2, s2 + leftSize - 1);
        root->right = build(inorder, index + 1, e1, postorder, s2 + leftSize, e2 - 1);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> inorder({4, 2, 5, 1, 6, 3, 7});
    vector<int> postorder({4, 5, 2, 6, 7, 3, 1});
    TreeNode *root = s.buildTree(inorder, postorder);
    root->print();
    return 0;
}
