/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
Note: There are at least two nodes in this BST.
 */

/*
 *
class Solution {
    int min_dif = INT_MAX, val = -1;
public:
int getMinimumDifference(TreeNode* root) {
    if (root->left != NULL) getMinimumDifference(root->left);
    if (val >= 0) min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) getMinimumDifference(root->right);
    return min_dif;
}
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
    int getMinimumDifference(TreeNode *root) {
        int res = INT_MAX;
        traverse(root, res);

        return res;
    }

    void traverse(TreeNode *root, int &res) {
        if (!root) {
            return;
        }
        int minRight = INT_MAX;
        int maxLeft = INT_MIN;
        if (root->left) {
            getMax(root->left, maxLeft);
            res = min(res, root->val - maxLeft);
        }
        if (root->right) {
            getMin(root->right, minRight);
            res = min(res, minRight - root->val);
        }
        traverse(root->left, res);
        traverse(root->right, res);
    }

    void getMax(TreeNode *root, int &max) {
        if (!root) {
            return;
        }
        if (root->val > max) {
            max = root->val;
        }
        getMax(root->left, max);
        getMax(root->right, max);
    }

    void getMin(TreeNode *root, int &min) {
        if (!root) {
            return;
        }
        if (root->val < min) {
            min = root->val;
        }
        getMin(root->left, min);
        getMin(root->right, min);
    }

};

int main() {
    Solution s;
    vector<int> preorder({236, 104, 227, 701, 911}), inorder({104, 227, 236, 701, 911});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.getMinimumDifference(root) << endl;
    preorder = {600, 424, 499, 612, 689};
    inorder = {424, 499, 600, 612, 689};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.getMinimumDifference(root) << endl; //12
    return 0;
}
