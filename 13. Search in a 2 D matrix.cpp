// Problem Statement:
// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.


// Problem Solution:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s=0,e=m*n-1;

        while(s<=e){
            int mid = s+(e-s)/2;
            int r = mid/n; 
            int c = mid%n;
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};
