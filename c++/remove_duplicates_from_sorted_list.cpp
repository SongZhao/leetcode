/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/*
 * note how to free memory
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
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p = head;
        while (p && p->next) {
            if (p->val == p->next->val) {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                delete tmp; // delete only works if the list node is allocated by new
            } else {
                p = p->next;
            }
        }
        return head;
    }
};


int main() {
    Solution s;
    vector<int> v1({1, 1, 1});
    ListNode *headA = buildList(v1);
    s.deleteDuplicates(headA);
    printList(headA);
    vector<int> v2({1, 1, 2, 3, 3});
    ListNode *headB = buildList(v2);
    s.deleteDuplicates(headB);
    printList(headB);

    return 0;
}
