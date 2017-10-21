/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/*
 * two pointers
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != p2) {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};


int main() {
    Solution s;
    vector<int> v1({1, 2});
    ListNode *headA = buildList(v1);
    vector<int> v2({3, 4, 5});
    ListNode *headB = buildList(v2);
    vector<int> v3({6, 7});
    ListNode *headC = buildList(v3);
    headA->next->next = headC;
    headB->next->next->next = headC;
    ListNode *intersection = s.getIntersectionNode(headA, headB);
    if (intersection) {
        cout << intersection->val << endl;
    } else {
        cout << "NULL" << endl;
    }
    return 0;
}
