/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of
 American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_map<char, int> dict;
        vector<string> tmp({"qwertyuiop", "asdfghjkl", "zxcvbnm"});
        for (int i = 0;i<tmp.size();i++) {
            for (char c:tmp[i]) {
                dict[c] = i;
            }
        }

        for (string word:words) {
            if (word.empty()) {
                continue;
            }
            int row = dict[tolower(word[0])];
            int i;
            for (i = 1;i<word.length();i++) {
                if (dict[tolower(word[i])] != row) {
                    break;
                }
            }
            if (i == word.length()) {
                res.push_back(word);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words;
    words = {"Hello", "Alaska", "Dad", "Peace"};
    cout << s.findWords(words) << endl;

    return 0;
}
