// Problem Statement:
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located 
// along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once 
// put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, 
// such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

// Example
// Input:
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// Output:
// 3

// Problem Solution:
bool possible(vector<int> &a,int mid,int cows)
{
    int cntCows=1,lastCow=a[0];
    for(int i=1;i<a.size();i++)

    {

        if(a[i]-lastCow>=mid)

        {

            cntCows++;

            lastCow =a[i];

        }

        if(cntCows == cows) return true;

    }

    return false;

}

int aggressiveCows(vector<int> &stalls, int k)

{

    int n=stalls.size();

    sort(stalls.begin(),stalls.end());

    int l=0,h=stalls[n-1]-stalls[0];

    int mid;

    while(l<=h)

    {

        mid=(l+h)/2;

        if(possible(stalls,mid,k))

        {

            l=mid+1;

        }else{

            h=mid-1;

        }

    }

    return h;

}
