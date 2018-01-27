/*
Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the
 root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:
      2
     /
    4
and
    4
Therefore, you need to return above trees' root in the form of a list.

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map;
        vector<TreeNode*> res;
        serialize(root, map);

        for (auto &it:map) {
            if (it.second.size() > 1) {
                res.push_back(it.second[0]);
            }
        }
        return res;
    }

    string serialize(TreeNode *root, unordered_map<string, vector<TreeNode*>> &map) {
        if (!root) {
            return "";
        }

        string s = "T" + to_string(root->val) + "L" + serialize(root->left, map) + "R" + serialize(root->right, map);
        map[s].push_back(root);

        return s;
    }
};

int main() {
    Solution s;
    vector<int> preorder({1, 2, 4, 3, 2, 4, 4}), inorder({4, 2, 1, 4, 2, 3, 4});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.findDuplicateSubtrees(root) << endl;

    return 0;
}
