/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to
 recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        map<int, int> dict;
        vector<int> res;
        traverse(root, dict);
        int maxCount = 0;
        for (auto &it:dict) {
            if (it.second > maxCount) {
                maxCount = it.second;
            }
        }
        for (auto &it:dict) {
            if (it.second == maxCount) {
                res.push_back(it.first);
            }
        }
        return res;
    }

    void traverse(TreeNode* root, map<int, int> &dict) {
        if (!root) {
            return;
        }
        dict[root->val]++;
        traverse(root->left, dict);
        traverse(root->right, dict);
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 2}), inorder({1, 2, 2});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.findMode(root) << endl;
    preorder = {1, 2}, inorder = {1, 2};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.findMode(root) << endl;
    preorder = {2, 2, 2}, inorder = {2, 2, 2};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.findMode(root) << endl;
    return 0;
}
