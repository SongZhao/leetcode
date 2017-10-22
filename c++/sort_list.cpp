/*
Sort a linked list in O(n log n) time using constant space complexity.
 */

/*
 * merge sort
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;

        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(fast);

        return mergeTwoLists(p1, p2);
    }

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
    vector<int> v({6, 1, 3, 4, 2, 5});
    ListNode *head = buildList(v);
    printList(s.sortList(head));

    return 0;
}
