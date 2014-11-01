'''
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
'''

'''
Classic combination problem. We can solve this using either recursive or iterative way. Time complexity is O(n^k), where n is the length of digits, and k is the average number of letters for each digit.
'''

class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        res = []
        self.letterCombinationsHelper(digits, 0, '', res)
        return res

    def letterCombinationsHelper(self, digits, index, current_string, res):
        mapping = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        if index == len(digits):
            res.append(current_string)
        else:
            for c in mapping[int(digits[index])]:
                current_string += c
                self.letterCombinationsHelper(digits, index + 1, current_string, res)
                # trace back
                current_string = current_string[:len(current_string) - 1]

    def letterCombinations1(self, digits):
        mapping = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        res = ['']
        tmp = []
        for d in digits:
            tmp = []
            for s in res:
                for c in mapping[int(d)]:
                    tmp.append(s + c)
            res = tmp
        return res


if __name__ == '__main__':
    s = Solution()
    print s.letterCombinations('23')
    print s.letterCombinations('')
    print s.letterCombinations1('23')
    print s.letterCombinations1('')

                
