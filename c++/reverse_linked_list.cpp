/*
Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
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
    vector<int> v1({1, 2, 3, 4, 5});
    ListNode *headA = buildList(v1);
    printList(s.reverseList(headA));

    return 0;
}
