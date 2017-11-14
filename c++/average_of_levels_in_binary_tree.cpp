/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        if (!root) {
            return res;
        }
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        double sum = 0;
        int count = 0, currentLevel = 0;
        while (!q.empty()) {
            TreeNode *tmp = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level == currentLevel) {
                sum += tmp->val;
                count++;
            } else {
                res.push_back(sum / count);
                currentLevel = level;
                sum = tmp->val;
                count = 1;
            }
            if (tmp->left) {
                q.push(make_pair(tmp->left, level + 1));
            }
            if (tmp->right) {
                q.push(make_pair(tmp->right, level + 1));
            }
        }
        res.push_back(sum / count);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> preorder({3, 9, 20, 15, 7}), inorder({9, 3, 15, 20, 7});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.averageOfLevels(root) << endl;

    return 0;
}
