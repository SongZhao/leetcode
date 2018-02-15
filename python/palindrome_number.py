'''
Determine whether an integer is a palindrome. Do this without extra space.
'''

'''
Assume x is a non-negtive number.
'''
class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        x = str(x)
        first = 0
        last = len(x) - 1
        while first <= last:
            if x[first] != x[last]:
                return False
            first += 1
            last -= 1
        return True

if __name__ == '__main__':
    s = Solution()
    print s.isPalindrome(12321)
    print s.isPalindrome(123321)
    print s.isPalindrome(123)
    print s.isPalindrome(0)
                
