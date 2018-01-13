/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return dfs(1, n);
    }

    vector<TreeNode *> dfs(int start, int end) {
        vector<TreeNode *> res;

        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }

        vector<TreeNode *> left, right;
        for (int i = start; i <= end; i++) {
            left = dfs(start, i - 1);
            right = dfs(i + 1, end);

            for (auto *lnode: left) {
                for (auto *rnode: right) {
                    auto *root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    for (auto node:s.generateTrees(3)) {
        node->print();
        cout << "------" << endl;
    }
    return 0;
}
