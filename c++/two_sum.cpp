/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

/*
Time complexity of brute force is O(n^2), thus will cause Time Limit Exceeded error. So we use hash map to save visited intergers, and the time compexity is O(n)
*/

#include "helper.h"
#include <unordered_map>

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ret;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
      if (hash.find(target - nums[i]) != hash.end()) {
        ret.push_back(hash[target - nums[i]]);
        ret.push_back(i);
        break;
      }
      hash[nums[i]] = i;
    }
    return ret; 
  }
};

int main() {
    Solution s;
    const int arr[] = {2,7,11,15};
    const int target = 9;
    vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]) );
    cout << v << endl;
    cout << s.twoSum(v, target) << endl;
    return 0;
}
