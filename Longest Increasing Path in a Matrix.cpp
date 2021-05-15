Question->
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1

Topic-> DFS, Memoisation

Code:

class Solution {
public:
    vector<vector<int>> visited,memo;
    
    vector<int> dirX={0,0,1,-1};
    vector<int>dirY={1,-1,0,0};
    
    int maxx;
    
    int dfs(vector<vector<int>>& matrix,int i,int j,int m,int n)
    {
        visited[i][j]=1;
        
        for(int d=0;d<4;d++)
        {
            int x=i+dirX[d],y=j+dirY[d];
            if(x>=0 && x<m && y>=0 && y<n && matrix[x][y]>matrix[i][j])
            {
                if(!visited[x][y])
                    memo[i][j]=max(memo[i][j],1+dfs(matrix,x,y,m,n));
                else
                    memo[i][j]=max(memo[i][j],1+memo[x][y]);
                
                maxx=max(maxx,memo[i][j]);
            }
        }
        return memo[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        visited.resize(m,vector<int>(n,0));
        memo.resize(m,vector<int>(n,1));
        maxx=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j]=1;
                    dfs(matrix,i,j,m,n);
                }
            }
        }
                
                
        return maxx;
    }
};
