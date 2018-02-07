/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level
 are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int countNodes(TreeNode *root) {
        int leftDepth = height(root, true);
        int rightDepth = height(root, false);

        return leftDepth == rightDepth ? (1 << leftDepth) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
    }

    int height(TreeNode *root, bool isLeft) {
        int res = 0;
        while (root) {
            root = isLeft ? root->left : root->right;
            res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 4, 3}), inorder({4, 2, 1, 3});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.countNodes(root) << endl;
    return 0;
}
