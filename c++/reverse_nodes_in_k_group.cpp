/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
 */

/*
 * On top of Reverse Linked List II
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *end = head;
        while (end) {
            for (int i = 0;i<k;i++) {
                if (end) {
                    end = end->next;
                } else {
                    return dummy.next;
                }
            }
            pre = reverse(pre, end);
        }
        return dummy.next;
    }

    ListNode *reverse(ListNode *pre, ListNode *end) {
        ListNode *cur = pre->next;
        while (cur->next != end) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next =pre->next;
            pre->next = tmp;
        }
        return cur;
    }
};


int main() {
    Solution s;
    vector<int> v({1, 2, 3, 4, 5});
    ListNode *head = buildList(v);
    //printList(s.reverseKGroup(head, 2));
    printList(s.reverseKGroup(head, 3));

    return 0;
}
