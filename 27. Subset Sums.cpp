// Problem Statement:
// Given a list arr of N integers, print sums of all subsets in it.

// Example 1:
// Input:
// N = 2
// arr[] = {2, 3}
// Output:
// 0 2 3 5
// Explanation:
// When no elements is taken then Sum = 0.
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then 
// Sum = 2+3 = 5.

// Example 2:
// Input:
// N = 3
// arr = {5, 2, 1}
// Output:
// 0 1 2 3 5 6 7 8

// Problem Solution:
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        if(N==0){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector<int> so = subsetSums(arr,N-1);
        vector<int> ans;
        int m = so.size();
        
        for(int i=0;i<m;i++){
            ans.push_back(so[i]);
        }
        for(int i=0;i<m;i++){
            ans.push_back(so[i]+arr[N-1]);
        }
        return ans;
    }
};
