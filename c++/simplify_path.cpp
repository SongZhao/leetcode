/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

/*
 *
*/

#include "helper.h"

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        string token;
        istringstream ss(path);
        vector<string> tokens;

        while (getline(ss, token, '/')) {
            if (token == "." || token.empty()) {
                continue;
            } else if (token == "..") {
                if (!tokens.empty()) {
                    tokens.pop_back();
                }
            } else {
                tokens.push_back(token);
            }
        }
        for (const string &str:tokens) {
            res += '/' + str;
        }
        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/a/.b/../../c/") << endl;
    cout << s.simplifyPath("/../") << endl;
    cout << s.simplifyPath("/home//foo/") << endl;

    return 0;
}
