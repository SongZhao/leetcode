/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

/*
 * 
*/

#include "helper.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if (strs.empty()) {
            return res;
        }
        for (int i = 0;i< strs[0].size();i++) {
            for (int j = 1;j < strs.size();j++) {
                if (strs[j][i] != strs[j-1][i]) {
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs({"abc", "a", "abcde"});
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
