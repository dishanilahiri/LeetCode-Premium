Question->

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.


I have used cycle detection to find if all courses can be studied. If there is a cycle i.e. completion of a particular course indirectly depends on it's own completion, there is no way we can study all courses.
  
Code:

class Solution {
public:
    bool isCycle(int src,vector<vector<int>> &graph,vector<bool> &visited,vector<bool> &recstack)
    {
        if(!visited[src])
        {
            visited[src]=true;
            recstack[src]=true;
            for(auto c:graph[src])
            {
                if(!visited[c] && isCycle(c,graph,visited,recstack))
                    return true;
                else if(recstack[c])
                    return true;
            }
        }        
        recstack[src]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<bool> visited(numCourses,false),recstack(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(isCycle(i,graph,visited,recstack))
                return false;
        }
        return true;
    }
};
