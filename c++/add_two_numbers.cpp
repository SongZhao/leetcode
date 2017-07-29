/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
The main idea is quite simple, but need to pay attention to edge cases, e.g. there is still carry after adding is done (1 + 99)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstddef>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0), *p = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
      if (l1) {
        carry += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        carry += l2->val;
        l2 = l2->next;
      }
      p->next = new ListNode(carry%10);
      carry /= 10;
      p = p->next;
    }
    return dummy->next;
  }
};

int main() {
  ListNode n1(2);
  ListNode n2(4);
  ListNode n3(3);
  n1.next = &n2;
  n2.next = &n3;
  ListNode l1(5);
  ListNode l2(6);
  ListNode l3(4);
  l1.next = &l2;
  l2.next = &l3;
  Solution s;
  ListNode *res = s.addTwoNumbers(&n1, &l1);
  cout << res->val << "->" << res->next->val << "->" << res->next->next->val << endl;
  return 0;
}
