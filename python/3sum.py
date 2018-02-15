'''
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
'''

'''
Sort the list first, and use two pointers to scan. To avoid duplicates, just increase pointer when next element is the same as previous element for both inter and outer loop.
'''
class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        res = []
        num.sort()
        i = 0
        while i < len(num):
            start = i + 1
            end = len(num) - 1
            while start < end and i != end:
                if num[i] + num[start] + num[end] == 0:
                    res.append([num[i], num[start], num[end]])
                    start += 1
                    end -= 1
                    #increase pointer if next element is the same to avoid duplicates
                    while start < end and num[start] == num[start-1]:
                        start += 1
                    while start < end and num[end] == num[end+1]:
                        end -= 1
                elif num[i] + num[start] + num[end] < 0:
                    start += 1
                else:
                    end -= 1
            #increase pointer for outer loop to avoid duplicate
            while i < len(num) - 1 and num[i] == num[i+1]:
                i += 1
            i += 1
        return res

if __name__ == '__main__':
    s = Solution()
    print s.threeSum([-1, 0, 1, 2, -1, -4])
    print s.threeSum([0, 0, 0, 0])
