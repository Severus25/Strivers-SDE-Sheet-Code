// Problem Statement:
// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which appears twice and B which is missing.
// Return A and B.
// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
// Note that in your output A should precede B.

// Example:
// Input:[3 1 2 5 3] 
// Output:[3, 4] 
// A = 3, B = 4

// Problem Solution
#include <bits/stc++.h>
using namespace std;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> ret(2);
    long long sumOfA = 0, sumOfA2 = 0;
    long long temp;
    int retA, retB;
    int n = A.size();
    for (int i = 0; i < n; i++) {
        temp = A[i];
        sumOfA += temp;
        sumOfA2 += temp*temp;
        temp = i + 1;
        sumOfA -= temp;
        sumOfA2 -= temp*temp;
    }
    sumOfA2 = sumOfA2/sumOfA;
    retA = (int)((sumOfA + sumOfA2)/2);
    retB = (int)(sumOfA2-retA);
    ret[0] = retA;
    ret[1] = retB;
    return ret;
}
