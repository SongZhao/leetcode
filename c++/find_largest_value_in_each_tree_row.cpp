/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
 */

/*
 * dfs
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        dfs(res, root, 0);
        return res;
    }

    void dfs(vector<int> &res, TreeNode *root, int level) {
        if (!root) {
            return;
        }
        if (level >= res.size()) {
            res.push_back(root->val);
        } else if (res[level] < root->val) {
            res[level] = root->val;
        }
        dfs(res, root->left, level + 1);
        dfs(res, root->right, level + 1);
    }
};

int main() {
    Solution s;
    int sum = 1;
    vector<int> preorder({1, 3, 5, 3, 2, 9}), inorder({5, 3, 3, 1, 2, 9});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.largestValues(root) << endl;

    return 0;
}
