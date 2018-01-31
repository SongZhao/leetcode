/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
Note:
The size of the given array will be in the range [1,1000].
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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode *dfs(const vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int maxVal = INT_MIN;
        int maxIndex = 0;
        for (int i = start; i <= end; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode(maxVal);
        root->left = dfs(nums, start, maxIndex - 1);
        root->right = dfs(nums, maxIndex + 1, end);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *root = s.constructMaximumBinaryTree(nums);
    root->print();

    return 0;
}
