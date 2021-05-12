Question->
Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
  
Topic-> DFS, BFS
Following solution uses DFS.

Code:

class Solution {
public:
    vector<int> dirX={0,0,1,-1};
    vector<int> dirY={1,-1,0,0};
    
    void solved(vector<vector<char>>& board,int i,int j,int m,int n)
    {
        board[i][j]='1';
        for(int d=0;d<4;d++)
        {
            int x=i+dirX[d],y=j+dirY[d];
            if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O')
                solved(board,x,y,m,n);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                solved(board,i,0,m,n);
            if(board[i][n-1]=='O')
                solved(board,i,n-1,m,n);
        }
        
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
                solved(board,0,i,m,n);
            if(board[m-1][i]=='O')
                solved(board,m-1,i,m,n);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='1')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
