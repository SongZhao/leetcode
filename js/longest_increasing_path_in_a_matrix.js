/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/

/*
 *
*/

var _ = require('lodash');

const directions = [[1, 0], [0, 1], [-1, 0], [0, -1]];

/**
 * @param {number[][]} matrix
 * @return {number}
 */
var longestIncreasingPath = function (matrix) {
    let res = 0, m = matrix.length, n = matrix[0].length, cache = [];
    for (let i = 0; i < m; i++) {
        let row = [];
        for (let j = 0; j < n; j++) {
            row.push(0);
        }
        cache.push(row);
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            res = _.max([res, dfs(matrix, i, j, m, n, cache)]);
        }
    }
    return res;
};

function dfs(matrix, i, j, m, n, cache) {
    if (cache[i][j] !== 0) {
        return cache[i][j];
    }
    let res = 1;
    for (let k in directions) {
        let dir = directions[k];
        let x = i + dir[0], y = j + dir[1];
        if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] <= matrix[i][j]) {
            continue;
        }
        let len = 1 + dfs(matrix, x, y, m, n, cache);
        res = _.max([res, len]);
    }
    cache[i][j] = res;
    return res;
}

(function () {
    let matrix = [
        [9, 9, 4],
        [6, 6, 8],
        [2, 1, 1]
    ];
    console.log(longestIncreasingPath(matrix));

    matrix = [
        [3, 4, 5],
        [3, 2, 6],
        [2, 2, 1]
    ];
    console.log(longestIncreasingPath(matrix));
})();