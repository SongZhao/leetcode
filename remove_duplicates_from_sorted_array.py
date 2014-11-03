'''
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
'''

'''
Use two pointers. Quite straightforward.
'''

class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if len(A) < 2:
            return len(A)
        p1 = 0
        p2 = 1
        while p2 < len(A):
            while p2 < len(A) and A[p1] == A[p2]:
                p2 += 1
            p1 += 1
            if p2 < len(A):
                A[p1] = A[p2]
        return p1

if __name__ == '__main__':
    s = Solution()
    A = [1, 1, 2, 2, 3]
    print s.removeDuplicates(A)
    print A
    A = [1, 1]
    print s.removeDuplicates(A)
    print A
