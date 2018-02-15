'''
Write a function to find the longest common prefix string amongst an array of strings.
'''

'''
Quite simple. Just compare the character of first string with rest strings, and append this character to the result, until a no-match is found
'''

class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        i = 0
        res = ''
        if len(strs) == 0:
            return res
        while True:
            c = ''
            for s in strs:
                #come to end of string, return current longest common prefix
                if len(s) <= i:
                    return res
                #first string, assign the next character to c
                if c == '':
                    c = s[i]
                #if not match, return the current longest common prefix
                else:
                    if c != s[i]:
                        return res
            res += c
            i += 1
        return res

if __name__ == '__main__':
    s = Solution()
    print s.longestCommonPrefix(['abc', 'abd', 'ab'])
    print s.longestCommonPrefix([])
    print s.longestCommonPrefix(['', ''])
    print s.longestCommonPrefix(['a'])


                
