/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 */

/*
 * Similar to "Convert Sorted List to Binary Search Tree"
*/

#include "helper.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return NULL;
        }

        return traverse(nums, 0, nums.size());
    }

    TreeNode *traverse(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = traverse(nums, start, mid);
        root->right = traverse(nums, mid + 1, end);
        return root;
    }
};


int main() {
    Solution s;
    vector<int> nums({1, 2, 3, 4, 5});
    TreeNode *root = s.sortedArrayToBST(nums);
    root->print();
    return 0;
}
