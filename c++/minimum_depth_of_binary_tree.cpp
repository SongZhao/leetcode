/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

/*
 * Simple tree traversal. Same as "104. Maximum Depth of Binary Tree"
*/

#include "helper.h"
#include <limits>

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
    int res = std::numeric_limits<int>::max();
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            traverse(root, 1);
            return res;
        }
    }
    void traverse(TreeNode *node, int depth) {
        if (!node->left && !node->right) {
            res = std::min(res, depth);
            return;
        }
        if (node->left) {
            traverse(node->left, depth + 1);
        }
        if (node->right) {
            traverse(node->right, depth + 1);
        }
    }
};

int main() {
    Solution s;
    auto *root = new TreeNode(1);
    root->insert(true, 2);
    root->insert(false, 3);
    root->left->insert(true, 4);
    root->left->insert(false, 5);
    root->right->insert(true, 6);
    root->right->insert(false, 7);
    root->print();
    cout << s.minDepth(root) << endl;
    return 0;
}
