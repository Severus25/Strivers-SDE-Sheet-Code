// Problem Statement:
// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example-1:
// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.

// Problem Solution:
class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int sum=0,len=0;
       unordered_map<int,int>mp;
       mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;   
            }
            else{
                len=max(len,i-mp[sum]);
            }
            
        } 
        return len;
    }
};
