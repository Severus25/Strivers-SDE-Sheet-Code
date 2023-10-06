// Problem Statement:
// Given two equally sized 1-D arrays A, B containing N integers each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum C valid sum combinations from all the possible sum combinations.

// Problem Constraints
// 1 <= N <= 105
// 1 <= A[i] <= 105
// 1 <= C <= N

// Input Format
// First argument is an one-dimensional integer array A of size N.
// Second argument is an one-dimensional integer array B of size N.
// Third argument is an integer C.

// Output Format
// Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

// NOTE:
// The returned array must be sorted in non-increasing order.


// Example Input
// Input 1:
//  A = [3, 2]
//  B = [1, 4]
//  C = 2

// Input 2:
//  A = [1, 4, 2, 3]
//  B = [2, 5, 1, 6]
//  C = 4

// Example Output
// Output 1:
//  [7, 6]
// Output 1:
//  [10, 9, 9, 8]

// Example Explanation
// Explanation 1:
//  7     (A : 3) + (B : 4)
//  6     (A : 2) + (B : 4)

// Explanation 2:
//  10   (A : 4) + (B : 6)
//  9   (A : 4) + (B : 5)
//  9   (A : 3) + (B : 6)
//  8   (A : 3) + (B : 5)

// Problem Solution:
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
     int n=A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    priority_queue<vector<int>> p;
    set<vector<int>> s;
    vector<int> v;
    p.push({A[0]+B[0],0,0});
    s.insert({0,0});
    while(C--)
    {
        auto top=p.top();
        p.pop();
        int i=top[1];
        int j=top[2];
        v.push_back(top[0]);
        auto f1=s.find({i+1,j});
        auto f2=s.find({i,j+1});
        if(f1==s.end() && i+1<A.size())
        {
            p.push({A[i+1]+B[j],i+1,j});
            s.insert({i+1,j});
        }
        if(f2==s.end() && j+1<B.size())
        {
            p.push({A[i]+B[j+1],i,j+1});
            s.insert({i,j+1});
        }
    }
    return v;
}

