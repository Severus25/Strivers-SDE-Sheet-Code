// Problem Statement:
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2
  
// Example 2:
// Input: nums = [3,1,3,4,2]
// Output: 3
  
// Problem Solution:
// Using Map Approach->
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        int duplicate = 0;
        for(auto i= 0; i<nums.size(); ++i)
        ++m[nums[i]];
        
        for(auto i : m)
        {
            if(i.second > 1)
            {
                duplicate = i.first;
                break;
            }
        }
        return duplicate;
    }
};

// Using Binary Search Approach->
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;
        while(low <=  high) {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums) {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
    }
};
