'''
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
'''

'''
Two pointers. Note that we only need to check from position 0 to len(haystack) - len(needle) + 1. This will reduce some unnecessary calculations.
'''

class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return an integer
    def strStr(self, haystack, needle):
        p1 = 0
        p2 = 0
        if len(needle) == 0:
            return 0
        while p1 < len(haystack) - len(needle) + 1:
            if haystack[p1] == needle[0]:
                p2 = p1
                while p2 < len(haystack) and p2 - p1 < len(needle):
                    if haystack[p2] != needle[p2-p1]:
                        break
                    p2 += 1
                if p2 - p1 == len(needle):
                    return p1
            p1 += 1
        return -1

if __name__ == '__main__':
    s = Solution()
    print s.strStr('abcd', 'cd')
