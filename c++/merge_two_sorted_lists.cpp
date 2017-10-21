/*
Merge two sorted linked lists and return it as a new list.
 The new list should be made by splicing together the nodes of the first two lists.
*/

/*
 * Easy
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *p1 = l1, *p2 = l2, *p = &dummy;
        while (p1 && p2) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;
        }
        if (p1) {
            p->next = p1;
        }
        if (p2) {
            p->next = p2;
        }
        return dummy.next;
    }
};


int main() {
    Solution s;
    vector<int> v1({1, 1});
    ListNode *headA = buildList(v1);
    vector<int> v2({1, 1, 1, 2, 3});
    ListNode *headB = buildList(v2);
    printList(s.mergeTwoLists(headA, headB));

    return 0;
}
