// Problem Statement:
// https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Problem Solution:
int NthRoot(int n, int m) {
  // Write your code here.
  int ans = -1;
  int low = 1;
  int high = m;
  while(low <= high)
  {
    int mid = (low + high)/2;
    if(pow(mid,n) == m)
    {
      ans = mid;
      break;
    }
    else if(pow(mid,n) > m)
    {
      high = mid - 1;
    }
    else if (pow(mid, n) < m)
    {
      low = mid + 1;
    }
  }
  return ans;
}
