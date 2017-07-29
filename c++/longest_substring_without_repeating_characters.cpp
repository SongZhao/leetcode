/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


/*
Use two pointers, i(current_pos) and last_pos. and use a dict visited to save the most recent position for a char. line "last_pos = max(visited[s[i]] + 1, last_pos)" is the key. When we find an existing char, only update last_pos if the most recent appearance of the char is larger than last_pos. And don't forget to calculate when iter is over and specical cases len(s) <= 1
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    }
};
