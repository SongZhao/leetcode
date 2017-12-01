/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

/*
 * sort or hash
*/

#include "helper.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> dict;

        for (string& key:strs) {
            string str(key);
            sort(key.begin(), key.end());
            if (dict.count(key) == 0) {
                vector<string> v = {str};
                dict[key] = v;
            } else {
                dict[key].push_back(str);
            }
        }

        for (auto &it:dict) {
            res.push_back(it.second);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << s.groupAnagrams(strs) << endl;
    return 0;
}
