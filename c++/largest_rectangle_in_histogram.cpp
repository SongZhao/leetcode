/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

/*
 * The most intuitive way is for each bar, get the left most and right most index which is higher than the bar. But the
 * time complexity is O(n2), and it throws "Time Limit Exceeded" error. So we need a stack solution. The idea is to
 * maintain a monotonically increasing stack. Loop throw the bar, if current bar is less higher than stack top, then
 * pop the stack and calculate the area. The width is current position - stack top position (0 if stack top is empty) - 1.
*/

#include "helper.h"

//class Solution {
//public:
//    int largestRectangleArea(vector<int> &heights) {
//        int max = 0;
//        for (int i = 0; i < heights.size(); ++i) {
//            int j = i + 1;
//            int k = i - 1;
//            while (j < heights.size() && heights[j] >= heights[i]) {
//                ++j;
//            }
//            while (k >= 0 && heights[k] >= heights[i]) {
//                --k;
//            }
//            if (heights[i] * (j - k - 1) > max) {
//                max = heights[i] * (j - k - 1);
//            }
//        }
//        return max;
//    }
//};

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> stack;
        int max = 0, i = 0;
        heights.push_back(0);
        while (i < heights.size()) {
            int t = stack.empty() ? -1 : stack.back();
            if (stack.empty() || heights[i] >= heights[stack.back()]) {
                stack.push_back(i++);
            } else {
                int index = stack.back();
                stack.pop_back();
                int width = stack.empty() ? i : i - stack.back() - 1;
                if (heights[index] * width > max) {
                    max = heights[index] * width;
                }
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {1};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {2, 1, 2};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {1, 2, 2};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {4,2,0,3,2,5};
    cout << s.largestRectangleArea(heights) << endl;
    heights = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
