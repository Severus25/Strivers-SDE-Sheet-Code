// Problem Statement:
// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
  
// Example 2:
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// Problem Solution:
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int row = grid.size();
      int col = grid[0].size();
      int time = 0;

      // count the total number of fresh oranges so that we can track if every orange goes rotten eventually
      int freshCount = 0;
      
      // store the locations of initially rotten oranges. Later, we will conduct BFS starting from these locations
      queue<pair<int, int>> rotOranges;

      // update freshCount and rotOranges
      for(int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
          if(grid[r][c] == 1){
            freshCount++;
          } else if(grid[r][c] == 2){
              rotOranges.push({r, c});
            }
          } 
        }

      // directions (N, E, S, W) to explore
      vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
      while(freshCount > 0 && !rotOranges.empty()){
        int n = rotOranges.size();
        for(int i = 0; i < n; i++){
          pair<int, int> toPop = rotOranges.front();
          rotOranges.pop();

          // check four directions and make neighbors go rotten if possible
          for(auto d: directions){
            int r = toPop.first + d.first;
            int c = toPop.second + d.second;
            if(r >= 0 && r < row && c >= 0 && c < col && grid[r][c] == 1){
              grid[r][c] = 2;
              freshCount--;
              rotOranges.push({r, c});
            }
          }
        }
        time++;
      }

      if(freshCount != 0) {
        return -1;
      }
      return time;
    }  
};
