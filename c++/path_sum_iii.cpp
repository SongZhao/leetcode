/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
 */

/*
 * Use a hash to keep previous sum and count
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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> dict;
        dict[0] = 1;
        return traverse(root, sum, 0, dict);
    }

    int traverse(TreeNode* root, int target, int sum, unordered_map<int, int> &dict) {
        if (!root) {
            return 0;
        }
        sum += root->val;

        int res= dict[sum - target];
        dict[sum]++;
        res += traverse(root->left, target, sum, dict) + traverse(root->right, target, sum, dict);
        dict[sum]--;
        return res;

    }
};

int main() {
    Solution s;
    int sum = 22;
    vector<int> preorder({5, 4, 11, 7, 2, 8, 13, 4, 5, 1}), inorder({7, 11, 2, 4, 5, 13, 8, 5, 4, 1});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.pathSum(root, sum) << endl;
    return 0;
}
