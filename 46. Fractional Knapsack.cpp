// Problem Statement:
// Given weights and values of N items, we need to put these items 
// in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

// Example 1:
// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 

// Example 2:
// Input:
// N = 2, W = 50
// values[] = {60,100}
// weight[] = {10,20}
// Output:
// 160.00
// Explanation:
// Total maximum value of item
// we can have is 160.00 from the given
// capacity of sack.

// Problem Solution:
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool fun(Item a,Item b)
    {
        return ((float)a.value/a.weight)>((float)b.value/b.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
      sort(arr,arr+n,fun); 
      double ans=0;
      for(int i=0;i<n;i++)
      {
          if(W>=arr[i].weight)
          {
              W=W-arr[i].weight;
              ans=ans+arr[i].value;
          }
          else
          {
              double val=((double)W/arr[i].weight)*arr[i].value;
              ans=ans+val;
              break;
          }
      }
      return ans;
    }
        
};
