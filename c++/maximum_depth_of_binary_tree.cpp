/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

/*
 * Simple tree traversal
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
    int max = 0;
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else {
            traverse(root, 1);
            return max;
        }
    }
    void traverse(TreeNode *node, int depth) {
        if (!node->left && !node->right) {
            max = std::max(max, depth);
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
    cout << s.maxDepth(root) << endl;
    return 0;
}
