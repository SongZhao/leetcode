/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/*
 * Mid of the list is root, left part is root->left, right part is root->right.
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode* mid = getMid(head);
        if (head == mid) {
            return new TreeNode(mid->val);
        }
        ListNode* tmp = head;
        while (tmp) {
            if (tmp->next == mid) {
                tmp->next = NULL;
                break;
            }
            tmp = tmp->next;
        }
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
    }

    ListNode* getMid(ListNode* head) {
        ListNode *tmp = head;
        while (tmp && tmp->next) {
            tmp = tmp->next->next;
            head = head->next;
        }
        return head;
    }
};


int main() {
    Solution s;
    vector<int> values({1, 2, 3, 4, 5, 6, 7});
    ListNode *head = buildList(values);
    printList(head);
    TreeNode* root = s.sortedListToBST(head);
    root->print();
    return 0;
}
