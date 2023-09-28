// Problem Statement:
// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move 
// are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot 
// move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:
// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.

// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.

// Problem Solution:
class Solution{
public:
    void dfs(int i,int j, vector<vector<bool>>&vis ,vector<vector<int>> &m ,vector<string>&ans,  string path,int n ){
        if(i==n-1&&j==n-1&&m[n-1][n-1]==1)
        {
            ans.push_back(path);    
            return ;
        }        
        vis[i][j]=true;
        //making a right dfs call
        if(i+1<n&&vis[i+1][j]==false&&m[i+1][j]==1){
            path+="D";
          dfs(i+1,j,vis,m,ans,path,n);
            path.pop_back();
        }
        if(j+1<n&&vis[i][j+1]==false&&m[i][j+1]==1){
            path+="R";
          dfs(i,j+1,vis,m,ans,path,n);
            path.pop_back();
        }     
        if(i-1>=0&&vis[i-1][j]==false&&m[i-1][j]==1){
            path+="U";
          dfs(i-1,j,vis,m,ans,path,n);
            path.pop_back();
        }        
        if(j-1>=0&&vis[i][j-1]==false&&m[i][j-1]==1){
            path+="L";
          dfs(i,j-1,vis,m,ans,path,n);
            path.pop_back();
        }
         vis[i][j]=false;   
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string path="";
        vector<vector<bool>>vis(n,vector<bool>(n, false));
        int i=0;
        int j=0;
        if(m[i][j]==0)return ans;
        dfs(i,j,vis,m,ans,path,n);
        return ans;   
    }
};
