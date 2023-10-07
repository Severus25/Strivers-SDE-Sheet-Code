// Problem Statement:
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
  
// Problem Solution:
class Solution {
public:
    vector<int> topKFrequent_heapSort(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        
        unordered_map<int, int> freq;

        for(auto i: nums) {
            freq[i]++;
        }

        for(auto i: freq) {
            pq.push({i.second, i.first});
            if(pq.size() > k)
               pq.pop();
        }

        vector<int> topK;
        while(pq.size()) {
            topK.push_back(pq.top().second);
            pq.pop();
        }
        return topK;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        return topKFrequent_heapSort(nums, k);
    }
};
