/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/*
 * get mid, reverse second part, then merge
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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        slow = head;

        fast = reverseList(fast);

        while (fast && slow) {
            ListNode *tmp = slow->next;
            slow->next = fast;
            slow = tmp;
            tmp = fast->next;
            fast->next = slow;
            fast = tmp;
        }
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};


int main() {
    Solution s;
    vector<int> v({1, 2, 3, 4, 5});
    ListNode *head = buildList(v);
    s.reorderList(head);
    printList(head);

    return 0;
}
