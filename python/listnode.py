class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def printList(self):
        p = self
        while p:
            print str(p.val) + ' -> ',
            p = p.next
        print 'ENDOFLIST'
