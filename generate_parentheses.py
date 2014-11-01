'''
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
'''

'''
DFS. number of left parenthesis should always not exceed number of right parentheiss. Time complexity is O(2^n)
'''


class Solution:
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        res = []
        self.generateparenthesisHelper(res, 0, 0, '', n)
        return res
        
    def generateparenthesisHelper(self, res, left, right, current_str, n):
        if left == right == n:
            res.append(current_str)
        elif left < right:
            return 
        else:
            if left < n:
                self.generateparenthesisHelper(res, left + 1, right, current_str + '(', n)
            self.generateparenthesisHelper(res, left, right + 1, current_str + ')', n)
                  
if __name__ == '__main__':
    s = Solution()
    print s.generateParenthesis(0)
    print s.generateParenthesis(1)
    print s.generateParenthesis(2)
    print s.generateParenthesis(3)
