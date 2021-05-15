Question->
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

 

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]], 
k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10. 
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 

Example 2:

Input: 
grid = 
[[0,1,1],
 [1,1,1],
 [1,0,0]], 
k = 1
Output: -1
Explanation: 
We need to eliminate at least two obstacles to find such a walk.
 

Constraints:

grid.length == m
grid[0].length == n
1 <= m, n <= 40
1 <= k <= m*n
grid[i][j] == 0 or 1
grid[0][0] == grid[m-1][n-1] == 0


Topic-> BFS

Code:
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        
        int minSteps=max(0,m+n-2),minStepsnextRound=minSteps;
        
        if(minSteps-1<=k)                       //comparing with minSteps-1 because minSteps contains [0,n-1] twice
            return minSteps;
        
        vector<vector<int>> visited(m,vector<int>(n,-1));
        
        visited[0][0]=k;
        
        vector<int> dirX={0,0,1,-1};
        vector<int> dirY={1,-1,0,0};
        
        queue<vector<int>> q;
        q.push({0,0,k});
        
        int steps=0,stepstoTarget;
        
        while(q.size())
        {
            int w=q.size();
            minSteps=minStepsnextRound;
            steps++;
            
            while(w--)
            {
                vector<int> f=q.front();
                q.pop();
                
                int r=f[0],c=f[1],k=f[2];
                
                for(int d=0;d<4;d++)
                {
                    int x=r+dirX[d],y=c+dirY[d];
                    
                    if(x<0 || x>=m || y<0 || y>=n)
                        continue;
                    
                    int kk=k-grid[x][y];
                    
                    if(visited[x][y]>=kk)
                        continue;
                    
                    stepstoTarget=m-x+n-y-2;
                    
                    if(stepstoTarget-1<=kk && stepstoTarget==minSteps-1)  
                        return steps+stepstoTarget;
                    
                    q.push({x,y,kk});
                    visited[x][y]=kk;
                    
                    minStepsnextRound=min(minStepsnextRound,stepstoTarget);
                }
            }
        }
        return -1;
    }
};






