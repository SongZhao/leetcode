'''
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
'''

'''
Time complexity of brute force is O(n^2), thus will cause Time Limit Exceeded error. So we use hash map to save visited intergers, and the time compexity is O(n)
'''
class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        visited = {}
        for i in xrange(len(num)):
            if target - num[i] in visited:
                return (visited[target - num[i]] + 1, i + 1)
            else:
                visited[num[i]] = i

if __name__ == '__main__':
    s = Solution()
    print s.twoSum([0, 4, 3, 0], 0)
    print s.twoSum([2, 7, 11, 15], 9)
    print s.twoSum([-3, 4, 3, 90], 0)


                    
                
