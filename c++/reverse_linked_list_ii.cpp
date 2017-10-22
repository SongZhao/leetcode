/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/*
 *
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur, *pre = &dummy;

        for (int i = 1; i < m; i++) {
            pre = pre->next;
        }
        cur = pre->next;
        for (int i = m; i < n; i++) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return dummy.next;
    }
};


int main() {
    Solution s;
    vector<int> v1({1, 2, 3, 4, 5});
    ListNode *headA = buildList(v1);
    printList(s.reverseBetween(headA, 2, 4));

    return 0;
}
