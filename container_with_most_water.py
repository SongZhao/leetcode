'''
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
'''

'''
Use two pointers, one is at the start and one is at the end. Move pointer of the shorter line to the middle. area = (end - start) * min(height[start], height[end]). end - start guarantees becoming smaller and smaller, so the min height of start and end needs to increase to get a larger area. Thus we move the shorter line to the middle to search for any larger area.
'''
class Solution:
    # @return an integer
    def maxArea(self, height):
        first = 0
        last = len(height) - 1
        max_area = 0
        while first < last:
            h = min(height[first], height[last])
            w = last - first
            if h * w > max_area:
                max_area = h * w
            if height[first] > height[last]:
                last -= 1
            else:
                first += 1
        return max_area

if __name__ == '__main__':
    s = Solution()
    print s.maxArea([1,3,5,3,5,2])
                
