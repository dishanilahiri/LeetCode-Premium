Question->
You are given an m x n integer matrix heights representing the height of each unit cell in a continent. The Pacific ocean touches the continent's left and top edges, and the Atlantic ocean touches the continent's right and bottom edges.

Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

Topics-> DFS,BFS
Following solution uses DFS.
  
Code #1 (TLE):
class Solution {
public:
    vector<int> dirX={0,0,1,-1};
    vector<int> dirY={1,-1,0,0};
     
    void dfsPacificAtlantic(vector<vector<int>> heights,int r,int c,int m,int n,set<pair<int,int>> &visiteddfs,bool &ans1,bool &ans2)
    {        
        if(r==0||c==0)
        {
            ans1=true;
        }
        
        if(r==m-1||c==n-1)
        {
            ans2=true;
        }
        
        visiteddfs.insert({r,c});
        
        int currheight=heights[r][c];
        
        for(int i=0;i<4;i++)
        {
            int x=r+dirX[i],y=c+dirY[i];
            
            if(x>=0 && x<m && y>=0 && y<n && visiteddfs.find({x,y})==visiteddfs.end() && heights[x][y]<=currheight)
            {
                dfsPacificAtlantic(heights,x,y,m,n,visiteddfs,ans1,ans2);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int m=heights.size(),n=heights[0].size();
        
        set<pair<int,int>> visiteddfs;
                
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool ans1=false,ans2=false;
                visiteddfs.clear();
                dfsPacificAtlantic(heights,i,j,m,n,visiteddfs,ans1,ans2);
                if(ans1 && ans2)
                    res.push_back({i,j});
            }
        }
        return res;
    }
};

Code #2 (All pass):

Smartly traverse blocks which have the possibility of being flooded into the oceans by back traversing from edge blocks i.e. instead of checking each block if it flows out to the ocean or not, start infiltrating from edge blocks (in contact with the oceans) to the main continent. Thus, there is no overlap of visited blocks per ocean and TLE is avoided.

class Solution {
public:
    vector<int> dirX={0,0,1,-1};
    vector<int> dirY={1,-1,0,0};
    
    void dfs(vector<vector<int>>& heights,vector<vector<bool>> &visited,int m,int n,int r,int c)
    {
        visited[r][c]=true;
        for(int i=0;i<4;i++)
        {
            int x=r+dirX[i],y=c+dirY[i];
            if(x>=0 && x<m && y>=0 && y<n && !visited[x][y] && heights[x][y]>=heights[r][c])
            {
                
                dfs(heights,visited,m,n,x,y);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> ans;
        
        vector<vector<bool>> pacific(m,vector<bool>(n,0));
        vector<vector<bool>> atlantic(m,vector<bool>(n,0));
        
        for(int i=0;i<m;i++)
        {
            dfs(heights,pacific,m,n,i,0);
            dfs(heights,atlantic,m,n,i,n-1);
        }
        
        for(int i=0;i<n;i++)
        {
            dfs(heights,pacific,m,n,0,i);
            dfs(heights,atlantic,m,n,m-1,i);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
