/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

/*
 *
*/

var _ = require('lodash');

/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function (s, t) {
    let map = [];
    for (let i in s) {
        map[s[i]] = 0;
    }
    for (let i in t) {
        map[t[i]]++;
    }
    let counter = t.length, begin = 0, end = 0, d = Number.MAX_SAFE_INTEGER, head = 0;
    while (end < s.length) {
        if (map[s[end++]]-- > 0) {
            counter--;
        }

        while (counter === 0) {
            if (end - begin < d) {
                d = end - begin;
                head = begin;
            }
            if (map[s[begin++]]++ === 0) {
                counter++;
            }
        }
    }
    return d === Number.MAX_SAFE_INTEGER ? '' : s.substr(head, d);
};

(function () {
    console.log(minWindow('a', 'a'));
    console.log(minWindow('ADOBECODEBANC', 'ABC'));
})();