/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

/*
 *
*/

var _ = require('lodash');

// Definition for an interval.
function Interval(start, end) {
    this.start = start;
    this.end = end;
}

/**
 * @param {Interval[]} intervals
 * @param {Interval} newInterval
 * @return {Interval[]}
 */
var insert = function (intervals, newInterval) {
    var res = [];
    var start , end, done = false, merged = false;
    _.forEach(intervals, function (interval) {
        if (interval.end < newInterval.start) {
            res.push(interval);
        } else if (interval.start > newInterval.end) {
            if (!done) {
                res.push(newInterval);
            }
            done = true;
            res.push(interval);
        } else {
            newInterval = new Interval(_.min([interval.start, newInterval.start]),  _.max([interval.end, newInterval.end]));
        }
    });
    if (!done) {
        res.push(newInterval);
    }
    return res;
};

(function () {
    var intervals = [new Interval(1, 5)];
    var newInterval = new Interval(6, 8)
    var res = insert(intervals, newInterval);
    console.log(JSON.stringify(res));

    intervals = [];
    newInterval = new Interval(5, 7)
    var res = insert(intervals, newInterval);
    console.log(JSON.stringify(res));

    intervals = [new Interval(1, 3), new Interval(6, 9)];
    newInterval = new Interval(2, 5)
    var res = insert(intervals, newInterval);
    console.log(JSON.stringify(res));

    intervals = [new Interval(1, 2), new Interval(3, 5), new Interval(6, 7), new Interval(8, 10), new Interval(12, 16)];
    newInterval = new Interval(4, 9);
    var res = insert(intervals, newInterval);
    console.log(JSON.stringify(res));
})();