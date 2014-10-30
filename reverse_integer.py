'''
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
'''

'''
We have two ways for this problem. One is using string manipulation and one is using interger manipulation.
Both are quite simple.
'''


class Solution:
    # @return an integer
    def reverse(self, x):
        isNeg = True if x < 0 else False
        stack = []
        res = ''
        for ch in str(abs(x)):
            stack.append(ch)
        if isNeg:
            res += '-'
        while len(stack) > 0:
            res += stack.pop()
        return int(res)

    def reverse1(self, x):
        res = 0
        sign = -1 if x < 0 else 1
        x = abs(x)
        while x > 0:
            res = res * 10 + x % 10
            x /= 10
        return res * sign

if __name__ == '__main__':
    s = Solution()
    print s.reverse(123)
    print s.reverse(-123)
    print s.reverse1(123)
    print s.reverse1(-123)
                
