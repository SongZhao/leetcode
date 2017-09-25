#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    void insert(bool left, int val) {
        left ? this->left = new TreeNode(val) : this->right = new TreeNode(val);
    }
    void print(int indent = 0) {
        if (this->left) {
            this->left->print(indent + 4);
        }
        if (this->right) {
            this->right->print(indent + 4);
        }
        if (indent) {
            cout << std::setw(indent) << ' ';
        }
        cout << this->val << endl;
    }
};

TreeNode *build(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
    if (s1 > e1 || s2 > e2) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[s1]);
    int index = -1;
    for (int i = s2; i <= e2; ++i) {
        if (inorder[i] == root->val) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return nullptr;
    }
    int leftSize = index - s2;
    root->left = build(preorder, s1 + 1, s1 + leftSize, inorder, s2, index - 1);
    root->right = build(preorder, s1 + leftSize + 1, e1, inorder, index + 1, e2);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<vector<T>> &v) {
    out << '[' << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << "\t" << v[i] << endl;
    }
    cout << "]" << endl;
    return out;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const map<T1, T2> &m) {
    if (m.empty()) {
        out << "{}";
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        out << it->first << ":" << it->second << ";";
    }
    return out;
}

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const unordered_map<T1, T2> &m) {
    if (m.empty()) {
        out << "{}";
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        out << it->first << ":" << it->second << ";";
    }
    return out;
}


