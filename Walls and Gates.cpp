Question->
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF

Example
Example1

Input:
[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output:
[[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

Explanation:
the 2D grid is:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
the answer is:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
Example2

Input:
[[0,-1],[2147483647,2147483647]]
Output:
[[0,-1],[1,2]]


Topics->BFS, DFS

Following solution is using BFS.  
 
#include <bits/stdc++.h>
using namespace std;

//gate=0,wall=-1,openspace=inf

bool safe(int x,int y,int m,int n)
{
    if(x<0 || x>=m || y<0 || y>=n)
    return false;
    return true;
}

void findDistances(vector<vector<int>> &rooms,int m,int n)
{
    queue<pair<int,int>> q;
    vector<vector<int>> visited(m,vector<int>(n,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(rooms[i][j]==0)
            q.push({i,j});
        }
    }
    if(!q.size())
    return;

    int step=0;
    vector<int> dirX={0,0,1,-1};
    vector<int> dirY={1,-1,0,0};

    while(q.size())
    {
        int s=q.size();
        while(s--)
        {
            pair<int,int> f=q.front();
            q.pop();
            if(rooms[f.first][f.second]!=-1 && rooms[f.first][f.second]!=0)
            rooms[f.first][f.second]=min(step,rooms[f.first][f.second]);

            for(int i=0;i<4;i++)
            {
                int x=f.first+dirX[i];
                int y=f.second+dirY[i];
                if(safe(x,y,m,n) && !visited[x][y] && rooms[x][y]!=-1 && rooms[x][y]!=0)
                {
                    q.push({x,y});
                    visited[x][y]=1;
                }
            }
        }
        step++;
    }
}

int main() {
    vector<vector<int>> rooms={{INT_MAX,INT_MAX,INT_MAX,INT_MAX,0},
        {INT_MAX,-1,-1,INT_MAX,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,-1,INT_MAX},
        {0,-1,-1,-1,INT_MAX},
        {INT_MAX,INT_MAX,INT_MAX,INT_MAX,0}};
    int m=rooms.size(),n=rooms[0].size();
    findDistances(rooms,m,n);
    //print
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        cout<<rooms[i][j]<< " ";
        cout<<endl;
    }
}
