/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

/*
 *
*/

#include "helper.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp;
        dfs(res, s, 0, tmp, 0);
        return res;
    }

    void dfs(vector<string> &res, const string &ip, int cur, const string &tmp, int count) {
        if (count > 4) {
            return;
        }
        if (count == 4 && cur == ip.length()) {
            res.push_back(tmp);
        }

        for (int i = 1; i < 4; i++) {
            if (cur + i > ip.length()) {
                break;
            }
            string s = ip.substr(cur, i);
            if ((s[0] == '0' && s.length() > 1) || (i == 3 && stoi(s) >= 256)) {
                continue;
            }
            dfs(res, ip, cur + i, tmp + s + (count == 3 ? "" : "."), count + 1);
        }
    }
};


int main() {
    Solution s;
    cout << s.restoreIpAddresses("25525511135") << endl;
    return 0;
}
