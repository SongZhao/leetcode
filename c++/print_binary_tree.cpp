/*
Print a binary tree in an m*n 2D string array following these rules:

1. The row number m should be equal to the height of the given binary tree.
2. The column number n should always be an odd number.
3. The root node's value (in string format) should be put in the exactly middle of the first row it can be put.
 The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part
 and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in
 the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree
 is none while the other is not, you don't need to print anything for the none subtree but still need to leave the
 space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space
 for both of them.
4. Each unused space should contain an empty string "".
5. Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   /
  3
 /
4
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].
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
    vector<vector<string>> printTree(TreeNode *root) {
        vector<vector<string>> res;
        if (!root) {
            return res;
        }
        int height = getHeight(root);
        int width = pow(2, height) - 1;
        for (int i = 0; i < height; i++) {
            res.push_back(vector<string>(width));
        }
        dfs(res, root, 0, 0, width - 1);
        return res;
    }

    int getHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void dfs(vector<vector<string>> &res, const TreeNode *root, int level, int start, int end) {
        if (!root) {
            return;
        }
        int mid = (end - start) / 2 + start;
        res[level][mid] = to_string(root->val);
        dfs(res, root->left, level + 1, start, mid - 1);
        dfs(res, root->right, level + 1, mid + 1, end);
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 4, 3}), inorder({2, 4, 1, 3});
    preorder = {10, 5, 15, 6, 20}, inorder = {5, 10, 6, 15, 20};
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.printTree(root) << endl;

    return 0;
}
