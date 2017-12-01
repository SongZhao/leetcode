/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/*
 *
*/

#include "helper.h"

//Definition for an interval.
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.empty()) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().end < intervals[i].start) {
                res.push_back(intervals[i]);
            } else {
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<Interval> intervals;
    intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    vector<Interval> res(s.merge(intervals));
    cout << '[' << endl;
    for (auto &it:res) {
        cout << '[' << it.start << "],[" << it.end << ']' << endl;
    }
    cout << ']' << endl;

    return 0;
}
