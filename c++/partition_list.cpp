/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/*
 * keep two lists and insert current node to corresponding list
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return head;
        }
        ListNode dummy(0);
        ListNode* p = &dummy, *q = nullptr, *head2 = nullptr;
        while (head) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                if (!q) {
                    head2 = head;
                    q = head;
                } else {
                    q->next = head;
                    q = q->next;
                }
            }
            head = head->next;
        }
        if (q) {
            q->next = nullptr;
        }
        p->next = head2;
        return dummy.next;
    }
};


int main() {
    Solution s;
    vector<int> v({1, 4, 3, 2, 5, 2});
    ListNode *head = buildList(v);
    s.partition(head, 3);
    printList(head);

    return 0;
}
