'''
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
'''

'''
A simple stack problem
'''

class Solution:
    # @return a boolean
    def isValid(self, s):
        left_parenthese = '[{('
        right_parenthese = ']})'
        stack = []
        for c in s:
            if c in left_parenthese:
                stack.append(c)
            elif c in right_parenthese:
                if len(stack) == 0:
                    return False
                if stack.pop() != left_parenthese[right_parenthese.index(c)]:
                    return False
        if len(stack) == 0:
            return True
        else:
            return False

if __name__ == '__main__':
    s = Solution()
    print s.isValid('')
    print s.isValid('(){[]}')
    print s.isValid('{]')
