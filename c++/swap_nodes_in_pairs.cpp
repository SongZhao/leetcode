/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

/*
 * k = 2 in reverse_nodes_in_k_group
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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *end = head;
        while (end) {
            for (int i = 0; i < 2; i++) {
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
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return cur;
    }
};


int main() {
    Solution s;
    vector<int> v({1, 2, 3, 4, 5});
    ListNode *head = buildList(v);
    printList(s.swapPairs(head));

    return 0;
}
