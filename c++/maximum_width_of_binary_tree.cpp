/*
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum
 width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in
 the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input:

           1
         /   \
        3     2
       / \     \
      5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input:

          1
         /
        3
       / \
      5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input:

          1
         / \
        3   2
       /
      5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 1, cur = 1, start = 1, end = 1;
        queue<pair<pair<TreeNode*, int>,int>> q;
        q.push(make_pair(make_pair(root, 1), 1));
        while (!q.empty()) {
            TreeNode *node = q.front().first.first;
            int level = q.front().first.second;
            int index = q.front().second;
            q.pop();

            if (level != cur) {
                res = max(res, end - start + 1);
                start = index;
                cur = level;
            }

            if (node->left) {
                q.push(make_pair(make_pair(node->left, level + 1), 2 * index));
            }
            if (node->right) {
                q.push(make_pair(make_pair(node->right, level + 1), 2 * index + 1));
            }
            end = index;
        }
        return max(res, end - start + 1);
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 3, 5, 6, 2, 9, 7}), inorder({6, 5, 3, 1, 2, 9, 7});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.widthOfBinaryTree(root) << endl;

    preorder = {1, 3, 5, 2}, inorder = {5, 3, 1, 2};
    root = buildTree(preorder, inorder);
    root->print();
    cout << s.widthOfBinaryTree(root) << endl;
    return 0;
}
