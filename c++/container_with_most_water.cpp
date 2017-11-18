/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines
 are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

/*
 * two pointers
*/

#include "helper.h"

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return  maxArea;
    }
};


int main() {
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.maxArea(heights) << endl;
    heights = {2, 1, 2};
    cout << s.maxArea(heights) << endl;
    heights = {1, 2, 2};
    cout << s.maxArea(heights) << endl;
    heights = {4, 2, 0, 3, 2, 5};
    cout << s.maxArea(heights) << endl;
    heights = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << s.maxArea(heights) << endl;

    return 0;
}
