// Problem Statement:
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]

// Problem Solution:
class Solution {
private:
    // Recursive function to generate permutations
    void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
        // Base case: If we have processed all elements, add the permutation to the result
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Recursion: Try all possible swaps for the current index
        for (int i = index; i < nums.size(); i++) {
            // Swap the elements at index and i
            swap(nums[index], nums[i]);
            // Recursively generate permutations for the remaining elements
            solve(nums, ans, index + 1);
            // Backtrack by swapping back to the original state
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index); // Start generating permutations from index 0
        return ans;
    }
};
