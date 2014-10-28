'''
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''

'''
The main idea is quite simple, but need to pay attention to edge cases, e.g. there is still carry after adding is done (1 + 99)
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        c = 0
        head = None
        pre = None
        while l1 and l2:
            if l1.val + l2.val + c >= 10:
                node = ListNode(l1.val + l2.val + c - 10)
                c = 1;
            else:
                node = ListNode(l1.val + l2.val + c)
                c = 0
            if not head:
                head = node
                pre = node
            else:
                pre.next = node
                pre = node
            l1 = l1.next
            l2 = l2.next
        #l1 is longer than l2
        while l1:
            if l1.val + c >= 10:
                node = ListNode(l1.val + c - 10)
                c = 1
            else:
                node = ListNode(l1.val + c)
                c = 0
            pre.next = node
            pre = node
            l1 = l1.next
        #ls is longer than l1
        while l2:
            if l2.val + c >= 10:
                node = ListNode(l2.val + c - 10)
                c = 1
            else:
                node = ListNode(l2.val + c)
                c = 0
            pre.next = node
            pre = node
            l2 = l2.next
        # adding is done, check if still has carry
        if c:
            node = ListNode(c)
            pre.next = node
            pre = node
        return head

if __name__ == '__main__':
    s = Solution()
    p1 = ListNode(2)
    p2 = ListNode(4)
    p3 = ListNode(3)
    p4 = ListNode(5)
    p1.next = p2
    p2.next = p3
    p3.next = p4
    l1 = p1
    n1 = ListNode(5)
    n2 = ListNode(6)
    n3 = ListNode(4)
    n1.next = n2
    n2.next = n3
    l2 = n1
    l = s.addTwoNumbers(l1, l2)
    while l:
        print l.val, ' -> ', 
        l = l.next
    print "\n"
    l1 = ListNode(5)
    l2 = ListNode(5)
    l = s.addTwoNumbers(l1, l2)
    while l:
        print l.val, ' -> ', 
        l = l.next
    print "\n"
    l1 = ListNode(1)
    n1 = ListNode(9)
    n2 = ListNode(9)
    n1.next = n2
    l2 = n1
    l = s.addTwoNumbers(l1, l2)
    while l:
        print l.val, ' -> ', 
        l = l.next
    print "\n"
