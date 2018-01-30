/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) {
            return nullptr;
        }

        if (root->val == key) {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            } else if (!root->left){
                TreeNode* right = root->right;
                delete root;
                return right;
            } else {
                TreeNode* minNode = root->right;
                while(minNode->left){
                    minNode = minNode->left;
                }
                root->val = minNode->val;
                root->right = deleteNode(root->right, root->val);
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

int main() {
    Solution s;
    vector<int> preorder({5, 3, 2, 4, 6, 7}), inorder({2, 3, 4, 5, 6, 7});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    TreeNode *node = s.deleteNode(root, 3);
    node->print();

    return 0;
}
