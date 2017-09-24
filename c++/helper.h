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


