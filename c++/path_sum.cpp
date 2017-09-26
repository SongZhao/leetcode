/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool found;

    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        found = false;
        traverse(root, 0, sum);
        return found;
    }

    void traverse(TreeNode *root, int sum, int target) {
        if (found || !root) {
            return;
        }
        if (!root->left && !root->right) {
            if (sum + root->val == target) {
                found = true;
            }
            return;
        }

        traverse(root->left, sum + root->val, target);
        traverse(root->right, sum + root->val, target);


    }
};

int main() {
    Solution s;
    int sum = 1;
    vector<int> preorder({1, 2}), inorder({2, 1});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.hasPathSum(root, sum) << endl;
    preorder = {5, 4, 11, 7, 2, 8, 13, 4, 1}, inorder = {7, 11, 2, 4, 5, 13, 8, 4, 1}, sum = 22;
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.hasPathSum(root, sum) << endl;
    preorder = {1}, inorder = {1}, sum = 1;
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.hasPathSum(root, sum) << endl;
    return 0;
}
