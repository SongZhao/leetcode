/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

/*
 * Divide and conquer. Time complexity is O(NlogN)
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode *res;
        int n = lists.size();
        while ( n > 1) {
            int mid = (n + 1) / 2;
            for (int i = 0; i < mid;i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + mid]);
            }
            n = mid;
        }
        return lists[0];
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
    vector<ListNode*> lists;
    vector<int> v1({2});
    ListNode *headA = buildList(v1);
    vector<int> v2({});
    ListNode *headB = buildList(v2);
    vector<int> v3({-1});
    ListNode *headC = buildList(v3);
    lists.push_back(headA);
    lists.push_back(headB);
    lists.push_back(headC);
    printList(s.mergeKLists(lists));

    return 0;
}
