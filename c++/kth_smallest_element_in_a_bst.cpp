/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 How would you optimize the kthSmallest routine?
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
    int count = 0;
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        traversal(root);
        return res;
    }

    void traversal(TreeNode* root) {
        if (root->left) {
            traversal(root->left);
        }
        count--;
        if (count == 0) {
            res = root->val;
            return;
        }
        if (root->right) {
            traversal(root->right);
        }
    }

};

int main() {
    Solution s;
    vector<int> preorder({3, 4, 1, 2, 5}), inorder({1, 4, 3, 2, 5});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.kthSmallest(root, 3) << endl;
    return 0;
}
