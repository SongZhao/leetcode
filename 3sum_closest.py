'''
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

'''
Similar to 3sum problem. No need to handle duplicate cases. 
'''
class Solution:
    # @return an integer
    def threeSumClosest(self, num, target):
        res = float('inf')
        num.sort()
        for i in xrange(len(num)):
            start = i + 1
            end = len(num) - 1
            while start < end and i != end:
                if abs(num[i] + num[start] + num[end] - target) < abs(res - target):
                    res = num[i] + num[start] + num[end]
                if num[i] + num[start] + num[end] == target:
                    return target
                elif num[i] + num[start] + num[end] < target:
                    start += 1
                else:
                    end -= 1
        return res

if __name__ == '__main__':
    s = Solution()
    print s.threeSumClosest([-1, 2, 1, -4], 1) 
