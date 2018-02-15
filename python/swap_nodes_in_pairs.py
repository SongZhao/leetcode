'''
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
'''

'''
Use a dummy head.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from python.listnode import ListNode

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        dummyHead = ListNode(0)
        dummyHead.next = head
        cur = dummyHead
        post = head
        while post and post.next:
            cur.next = post.next
            post.next = post.next.next
            cur.next.next = post
            cur = post
            post = post.next
        return dummyHead.next

if __name__ == '__main__':
    s = Solution()
    n1 = ListNode(1)
    n2 = ListNode(2)
    n3 = ListNode(3)
    n4 = ListNode(4)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    head = n1
    head.printList()
    s.swapPairs(head).printList()
