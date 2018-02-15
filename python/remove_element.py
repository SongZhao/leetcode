'''
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
'''

'''
Two pointers. Straightforward.
'''

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        p1 = 0
        p2 = 0
        while p2 < len(A):
            if A[p2] != elem:
                A[p1] = A[p2]
                p1 += 1
            p2 += 1
        return p1

if __name__ == '__main__':
    s = Solution()
    A = [1, 2, 3, 4]
    print s.removeElement(A, 1)
    print A
