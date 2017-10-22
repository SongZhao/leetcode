/*
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode *cur = head, *pre;
        while (cur) {
            pre = &dummy;
            while (pre->next && pre->next->val <= cur->val) {
                pre = pre->next;
            }
            ListNode *tmp = pre->next;
            pre->next = cur;
            cur = cur->next;
            pre->next->next = tmp;
        }
        return dummy.next;
    }
};


int main() {
    Solution s;
    vector<int> v({6, 1, 3, 4, 2, 5});
    ListNode *head = buildList(v);
    printList(s.insertionSortList(head));

    return 0;
}
