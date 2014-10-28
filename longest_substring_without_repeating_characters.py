'''
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
'''

'''
Use two pointers, i(current_pos) and last_pos. and use a dict visited to save the most recent position for a char. line "last_pos = max(visited[s[i]] + 1, last_pos)" is the key. When we find an existing char, only update last_pos if the most recent appearance of the char is larger than last_pos. And don't forget to calculate when iter is over and specical cases len(s) <= 1
'''
class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        if len(s) <= 1:
            return len(s)
        max_len = 0
        visited = {}
        last_pos = 0
        for i in xrange(len(s)):
            if s[i] not in visited:
                visited[s[i]] = i
            else:
                if i - last_pos > max_len:
                    max_len = i - last_pos
                last_pos = max(visited[s[i]] + 1, last_pos)
                visited[s[i]] = i
        if i + 1 - last_pos > max_len:
            max_len = i + 1 - last_pos
        return max_len

if __name__ == '__main__':
    s = Solution()
    print s.lengthOfLongestSubstring('abcdbbadc')
    print s.lengthOfLongestSubstring('bbbbb')
    print s.lengthOfLongestSubstring('wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco')
    print s.lengthOfLongestSubstring('qopubjguxhxdipfzwswybgfylqvjzhar')
    print s.lengthOfLongestSubstring('')
               
