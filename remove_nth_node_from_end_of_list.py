'''
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

      After removing the second node from the end, the linked list becomes 1->2->3->5.
      Note:
      Given n will always be valid.
      Try to do this in one pass.
'''

'''
Classic two pointers problem. Edge case: delete the first Node
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from listnode import ListNode

class Solution:
    # @return a ListNode
    def removeNthFromEnd(self, head, n):
        p1 = head
        p2 = head
        pre = None
        for i in xrange(n):
            p2 = p2.next
        #delete the first node
        if p2 == None:
            return head.next
        while p2:
            pre = p1
            p1 = p1.next
            p2 = p2.next
        pre.next = p1.next if p1 else None
        return head
       

if __name__ == '__main__':
    s = Solution()
    n1 = ListNode(1)
    n2 = ListNode(2) 
    n3 = ListNode(3) 
    n4 = ListNode(4) 
    n5 = ListNode(5)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    head = n1
    head.printList()
    s.removeNthFromEnd(head, 2).printList() 
    n1 = ListNode(1)
    head = n1
    print s.removeNthFromEnd(head,1)
    n1 = ListNode(1)
    n2 = ListNode(2)
    n1.next = n2
    head = n1
    s.removeNthFromEnd(head, 2).printList()
