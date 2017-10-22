/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }
        int len = 1;
        ListNode *end = head;
        while (end -> next) {
            end = end->next;
            len++;
        }
        k = k % len;
        ListNode *p = head;
        for (int i = 0;i<len - k - 1;i++) {
            p = p->next;
        }
        end->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};


int main() {
    Solution s;
    vector<int> v({1, 2, 3, 4, 5});
    ListNode *head = buildList(v);
    printList(s.rotateRight(head, 2));

    return 0;
}
