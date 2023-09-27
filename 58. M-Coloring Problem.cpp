// Problem Statement:
// Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two 
// adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. 
// Print 1 if it is possible to colour vertices and 0 otherwise.

// Example 1:
// Input:
// N = 4
// M = 3
// E = 5
// Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
// Output: 1
// Explanation: It is possible to colour the
// given graph using 3 colours.

// Example 2:
// Input:
// N = 3
// M = 2
// E = 3
// Edges[] = {(0,1),(1,2),(0,2)}
// Output: 0

// Problem Solution:
class Solution{
public:
// check whether a particular color can be applied to the node
    bool safe(int node,int color[],bool graph[101][101],int n,int col){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }
        }
        return true;
    }
    // for each node we will try color 1 to m
    bool solve(int node,int color[],bool graph[101][101],int m,int n){
        if(node==n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(safe(node,color,graph,n,i)){
                color[node]=i;
           if(solve(node+1,color,graph,m,n)) return true;
           color[node]=0;
            }
        }
        return false;
    }
// color of all node=0
    bool graphColoring(bool graph[101][101], int m, int n) {
       int color[n]={0};
       if(solve(0,color,graph,m,n)){
           return true;
       }
       return false;
    }
};
