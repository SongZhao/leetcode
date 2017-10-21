/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/*
 * Keep track of previous node. How to free memory?
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
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head, *pre = &dummy;
        while (p && p->next) {
            if (p->val == p->next->val) {
                while (p && p->next && p->val == p->next->val) {
                    p = p->next;
                }
                pre->next = p->next;
                p = p->next;
            } else {
                pre = p;
                p = p->next;
            }
        }
        return dummy.next;
    }
};


int main() {
    Solution s;
    vector<int> v1({1, 1});
    ListNode *headA = buildList(v1);
    printList(s.deleteDuplicates(headA));
    vector<int> v2({1, 1, 1, 2, 3});
    ListNode *headB = buildList(v2);
    printList(s.deleteDuplicates(headB));

    return 0;
}
