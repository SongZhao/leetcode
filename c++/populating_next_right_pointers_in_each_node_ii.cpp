/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 */

/*
 * Similar to "Populating Next Right Pointers in Each Node", but have one more point to keep track of last node of
 * current level
*/

#include "helper.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) { return; }
        TreeLinkNode *p = root;
        TreeLinkNode *first = NULL;
        TreeLinkNode *last = NULL;
        while (p) {
            if (!first) {
                if (p->left) {
                    first = p->left;
                } else if (p->right) {
                    first = p->right;
                }
            }
            if (p->left) {
                if (last) {
                    last->next = p->left;
                }
                last = p->left;
            }
            if (p->right) {
                if (last) {
                    last->next = p->right;
                }
                last = p->right;
            }
            if (p->next) {
                p = p->next;
            } else {
                p = first;
                last = NULL;
                first = NULL;
            }
        }
    }
};