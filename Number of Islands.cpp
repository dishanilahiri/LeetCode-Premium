Question->
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
  
Topics->BFS, DFS
Following solution is using DFS.
  
Tip-> Using a separate visited array or set will lead to TLE. So it's better to manipulate the inital matrix such that time and memory can be saved. Whichever islands have been processed can be changed to water i.e. '0'.
Code:

class Solution {
public:
    void dfs(int x,int y,int m,int n,vector<vector<char>> &grid)
    {
        if(x<0||x>=m||y<0||y>=n)
            return;
        grid[x][y]='0';
        int dirX[]={0,0,1,-1};
        int dirY[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int r=x+dirX[i],c=y+dirY[i];
            if(r<0||r>=m||c<0||c>=n||grid[r][c]=='0')
                continue;
            dfs(r,c,m,n,grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),islands=0;
        
        //vector<vector<int>> visited(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    
                    dfs(i,j,m,n,grid);
                }
            }
        }
        return islands;
    }
};
