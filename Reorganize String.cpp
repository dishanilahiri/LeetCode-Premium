Question->
Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
Note:

s will consist of lowercase letters and have length in range [1, 500].

Topic-> String

Code:

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto it:m)
            pq.push({it.second,it.first});
        
        string ans;
        
        while(pq.size())
        {
            pair<int,char> t1=pq.top();
            pq.pop();
            if(!pq.size())
            {
                if(t1.first>1)
                    return "";
                else
                    return ans+t1.second;
            }
            
            pair<int,char> t2=pq.top();
            pq.pop();
            pair<int,char> maxx;
            if(t1.first<t2.first)
            {
                maxx=t2;
                t2=t1;
                t1=maxx;
            }
            
            
            for(int i=0;i<t2.first;i++)
            {
                ans+=t1.second;
                ans+=t2.second;
            }
            
            int left = t1.first-t2.first;

            if(left)
            {
                pq.push({left,t1.second});
            }
        }
        return ans;
    }
};
