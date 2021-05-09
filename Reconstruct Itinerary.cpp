Question->
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

  
  
Another example for clarification's sake->
Input: tickets = [["JFK","NRT"],["JFK","KUL"],["NRT","JFK"]]
Output: ["JFK","NRT","JFK","KUL"]

Output is not ["JFK","KUL","NRT","JFK"]
because the trip is actually {JFK->NRT->JFK->KUL}
and NOT {JFK->KUL->NRT->JFK}

Topics-> DFS, Topological Sort

Code:

class Solution {
public:
    void dfs(string airport,map<string,multiset<string>> &adj,vector<string> &ans)
    {
        while(adj[airport].size())
        {
            string nextairport=*(adj[airport].begin());
            adj[airport].erase(adj[airport].begin());
            dfs(nextairport,adj,ans);
        }
        ans.push_back(airport);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> adj;                               //map<string,priority_queue<string,greater<string>>> adj or even map<string,vector<string>> can also be used but extra sorting step is needed for the latter case to maintain lexicographical order.
        
        for(int i=0;i<tickets.size();i++)
        {
            string from=tickets[i][0];
            string to=tickets[i][1];
            adj[from].insert(to);
        }
           
        
        vector<string> ans;
        dfs("JFK",adj,ans);
        return vector<string>(ans.rbegin(),ans.rend());
    }
};
