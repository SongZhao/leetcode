/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
 sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

*/

/*
 * BFS
*/

#include "helper.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (wordList.empty()) {
            return 0;
        }
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<int, string>> q;
        q.push(make_pair(2, beginWord));
        while (!q.empty()) {
            string cur = q.front().second;
            int level = q.front().first;
            q.pop();

            for (int i = 0;i<cur.length();i++) {
                char tmp = cur[i];
                for (char c = 'a';c<='z';c++) {
                    cur[i] = c;
                    if (wordSet.count(cur)) {
                        if (cur == endWord) {
                            return level;
                        }
                        q.push(make_pair(level + 1, cur));
                        wordSet.erase(cur);
                    }
                }
                cur[i] = tmp;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<string> wordList;
    wordList = {"peale", "wilts", "place", "fetch", "purer", "pooch", "peace", "poach", "berra", "teach", "rheum",
                "peach"};
    cout << s.ladderLength("teach", "place", wordList) << endl;
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;

    return 0;
}
