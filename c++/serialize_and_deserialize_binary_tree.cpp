/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored
 in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or
 another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your
 serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized
 to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to
 follow this format, so please be creative and come up with different approaches yourself.



Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should
 be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        doSerialize(root, res);
        return res;
    }

    void doSerialize(TreeNode *root, string &res) {
        if (!root) {
            res += "N,";
        } else {
            res += to_string(root->val) + ',';
            doSerialize(root->left, res);
            doSerialize(root->right, res);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            q.push(item);
        }
        return doDeserialize(q);
    }

    TreeNode* doDeserialize(queue<string>& q) {
        string &s = q.front();
        q.pop();
        if (s == "N") {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(stoi(s));
            root->left = doDeserialize(q);
            root->right = doDeserialize(q);
            return root;
        }
    }
};

int main() {
    Codec s;
    vector<int> preorder({1, 2, 4, 3}), inorder({4, 2, 1, 3});
    TreeNode *root = buildTree(preorder, inorder);
    root->print();
    cout << s.serialize(root) << endl;
    TreeNode* node = s.deserialize(s.serialize(root));
    node->print();
    return 0;
}
