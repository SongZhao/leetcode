/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area,
 called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart
 thief realized that "all houses in this place forms a binary tree". It will automatically contact the police
 if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

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
    unordered_map<TreeNode*, int> map;
    int rob(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (map.count(root)) {
            return map[root];
        }
        int left =  root->left ? (rob(root->left->left) + rob(root->left->right)) : 0;
        int right = root->right ? (rob(root->right->left) + rob(root->right->right)) : 0;
        map[root] = max(rob(root->left) + rob(root->right), root->val + left + right);
        return map[root];
    }
};

int main() {
    Solution s;
    vector<int> preorder({6, 2, 0, 4, 3, 5, 8, 7, 9}), inorder({0, 2, 3, 4, 5, 6, 7, 8, 9});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.rob(root) << endl;
    return 0;
}
