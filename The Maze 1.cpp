Question->
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1:
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2:
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)
Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

Topics-> BFS, DFS

Following solution uses BFS.

Question clarification-> Ball will stop only when it is stopped by a wall. 
Wall in the same direction as that of rolling ball will only stop the ball.
As this is a source and destination question, the direction of ball is crucial.

If ball is rolling currently, it will stay in motion till a wall stops it. When a wall stops it, one can check if it is the destination or not.
Also, there is no point of adding those locations through which ball has rolled by as we cannot change direction of ball while in rolling motion. So, it will be a redundant step.

Code:

#include <bits/stdc++.h>
using namespace std;

bool hasPath(vector<vector<int>> maze,vector<int> start,vector<int> destination)
{
    int m=maze.size(),n=maze[0].size();

    queue<pair<int,int>> q;
    vector<vector<int>> visited(m,vector<int>(n,0));
    q.push({start[0],start[1]});
    visited[start[0]][start[1]]=1;

    
    vector<int> dirX={0,0,1,-1};
    vector<int> dirY={1,-1,0,0};

    while(q.size())
    {
        pair<int,int> f=q.front();
        q.pop();
        int r=f.first,c=f.second;
        if(r==destination[0] && c==destination[1])
        return true;

        for(int i=0;i<4;i++)
        {
            int x=r,y=c;
            while(x>=0 && x<m && y>=0 && y<n && maze[x][y]==0)
            {
                x+=dirX[i],y+=dirY[i];
            }
            x-=dirX[i],y-=dirY[i];
            if(visited[x][y])
            continue;
            
            visited[x][y]=1;
            q.push({x,y});
        }
    }
    return false;
}

int main() {
    vector<vector<int>> maze={{0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 0},
                               {0, 0, 0, 1, 0},
                               {1, 1, 0, 1, 1},
                               {0, 0, 0, 0, 0}};
    
    vector<int> start={0,4},dest={4,4};
    cout<<hasPath(maze,start,dest);
    }
