/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 */

/*
 * BFS or DFS. Need to get depth first to allocate vector.
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        int depth = getDepths(root);
        vector<vector<int>> res(depth);
        if (depth == 0) {
            return res;
        }

        traverse(res, root, 0);
        return res;
    }

    void traverse(vector<vector<int>> &res, TreeNode *root, int level) {
        if (!root) {
            return;
        }
        res[level].push_back(root->val);
        traverse(res, root->left, level + 1);
        traverse(res, root->right, level + 1);
    }

    int getDepths(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = getDepths(root->left);
        int right = getDepths(root->right);
        return std::max(left, right) + 1;

    }
};

int main() {
    Solution s;
    vector<int> preorder({3, 9, 20, 15, 7}), inorder({9, 3, 15, 20, 7});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.levelOrder(root) << endl;
    return 0;
}
