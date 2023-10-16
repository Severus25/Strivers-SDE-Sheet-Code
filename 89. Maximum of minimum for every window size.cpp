// Problem Statement:
// https://www.codingninjas.com/studio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Problem Solution:
#include <bits/stdc++.h> 

vector<int> maxMinWindow(vector<int> a, int n) {

    // Write your code here.

    vector<int> nextSmallerIndexes(n,n);

    vector<int> prevSmallerIndexes(n,-1);

    stack<int> st1;

    for(int i=n-1;i>=0;i--)

    {

        while(!st1.empty() and a[i]<=a[st1.top()])

            st1.pop();

        if(!st1.empty())

            nextSmallerIndexes[i]=st1.top();

        st1.push(i);

    }

    stack<int> st2;

    for(int i=0;i<n;i++)

    {

        while(!st2.empty() and a[i]<=a[st2.top()])

            st2.pop();

        if(!st2.empty())

            prevSmallerIndexes[i]=st2.top();

        st2.push(i);

    }

    

    vector<int> ans(n,INT_MIN);

    for(int i=0;i<n;i++)

    {

        int size = nextSmallerIndexes[i]-prevSmallerIndexes[i]-1;

        ans[size-1]=max(ans[size-1],a[i]);

    }

    for(int i=ans.size()-2;i>=0;i--)

        ans[i]=max(ans[i],ans[i+1]);

    return ans;

}
