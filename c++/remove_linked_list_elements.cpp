/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
 */

/*
 * Use delete to free space?
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
    ListNode *removeElements(ListNode *head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head) {
            return head;
        }

        ListNode *p = head;
        while (p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};


int main() {
    Solution s;
    vector<int> v1({6, 6, 6, 1, 2, 6, 6, 6, 3, 4, 5, 6, 6, 6});
    ListNode *head = buildList(v1);
    printList(s.removeElements(head, 6));
    printList(s.removeElements(nullptr, 6));
    vector<int> v2({6, 6, 6});
    ListNode *head2 = buildList(v2);
    printList(s.removeElements(head2, 6));

    return 0;
}
