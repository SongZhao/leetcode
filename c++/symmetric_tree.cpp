/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
 */

/*
 * need to satisfy three conditions to be true. root->left->val == root->right->val,
 * tree(root->left->left) == tree(root->right->right), tree(root->left->right) == tree(root->right->left)
*/

#include "helper.h"
#include <queue>

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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        } else if (left && right) {
            return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
        } else {
            return false;
        }
    }
};

//iterative solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!left && !right) {
            return true;
        } else if (!left || !right) {
            return false;
        } else {
            queue<TreeNode*> q1,q2;
            q1.push(root->left);
            q2.push(root->right);
            while (!q1.empty() && !q2.empty()) {
                TreeNode* tmp1 = q1.front();
                TreeNode* tmp2 = q2.front();
                q1.pop();
                q2.pop();
                if (tmp1 && tmp2) {
                    if (tmp1->val != tmp2->val) {
                        return false;
                    }
                    q1.push(tmp1->left);
                    q1.push(tmp1->right);
                    q2.push(tmp2->right);
                    q2.push(tmp2->left);
                } else if (tmp1 || tmp2){
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 3, 4, 2, 4, 3}), inorder({3, 2, 4, 1, 4, 2, 3});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.isSymmetric(root) << endl;
    preorder = {1, 2, 3, 2, 3}, inorder = {2, 3, 1, 2, 3};
    TreeNode *root1 = buildTree(preorder, inorder);
    root1->print();
    cout << s.isSymmetric(root1) << endl;
    return 0;
}
