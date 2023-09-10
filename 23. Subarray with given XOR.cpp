// Problem Statement:
// Given an array of integers A and an integer B.
// Find the total number of subarrays having bitwise XOR of all elements equals to B.

// Input Format
// The first argument given is the integer array A.
// The second argument given is integer B.

// Output Format
// Return the total number of subarrays having bitwise XOR equals to B.

// Problem Solution:
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int xor_sum = 0;
    int count = 0;
    unordered_map<int, int> xor_count;
    for (int i = 0; i < n; i++) {
        xor_sum ^= A[i];
        if (xor_sum == B) {
            count++;
        }
        if (xor_count.find(xor_sum ^ B) != xor_count.end()) {
            count += xor_count[xor_sum ^ B];
        }
        xor_count[xor_sum]++;
    }
    return count;
}
