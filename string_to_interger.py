'''
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
'''

'''
The hardest part of this problem is dealing with edge cases.
1. empty string
2. string with leading white spaces
3. greater than INT_MAX or less than INT_MIN
4. plus or minus sign
5. invalid characters: if the first char is invalid, return 0. 
   If invalid char is not first, ignore chars afterwards.
'''

class Solution:
    # @return an integer
    def atoi(self, str):
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        #strip white spaces
        str = str.strip()
        if not str:
            return 0
        sign = 1
        res = 0
        #check first char, sign or not valid 
        if not (str[0] >= '0' and str[0] <= '9'):
            if str[0] == '+':
                str = str[1:]
            elif str[0] == '-':
                str = str[1:]
                sign = -1
            else:
                return 0
        #strip invalid chars
        for i in xrange(len(str)):
            if not (str[i] >= '0' and str[i] <= '9'):
                str = str[:i]
                break
        for i in xrange(len(str)):
            digit = ord(str[i]) - ord('0')
            if INT_MAX - res * 10 - digit <= 0 and sign > 0:
                return INT_MAX
            elif INT_MIN + res * 10 + digit >=0 and sign < 0:
                return INT_MIN
            else:
                res = res * 10 + digit
        return res * sign

if __name__ == '__main__':
    s = Solution()
    print s.atoi('1234')
    print s.atoi('-1234')
    print s.atoi('1234abc')
    print s.atoi('abc1234')
    print s.atoi('')
    print s.atoi('   010')
    print s.atoi('   ')
