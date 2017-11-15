/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that
 their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> set;
        return traverse(root, k, set);
    }

    bool traverse(TreeNode *root, int k, unordered_set<int> &set) {
        if (!root) {
            return false;
        }
        if (set.count(k - root->val)) {
            return true;
        }
        set.insert(root->val);
        return traverse(root->left, k, set) || traverse(root->right, k, set);
    }
};

int main() {
    Solution s;
    vector<int> preorder({5, 3, 2, 4, 6, 7}), inorder({2, 3, 4, 5, 6, 7});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.findTarget(root, 9) << endl;
    cout << s.findTarget(root, 28) << endl;
    return 0;
}
