Question->
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
 

Constraints:

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] only consists of English lowercase letters.

Topic-> Memoisation, DFS

Code:
class Solution {
public:
    int maxx;
    map<string,int> visited;
    
    bool isPoss(string src,string target)
    {
        for(int i=0,j=0;i<src.size() && j<target.size();i++,j++)
        {
            if(src[i]!=target[i])
            {
                int x=src.compare((target.substr(0,i)+target.substr(i+1,target.size()-i+1)));
                if(!x)
                    return true;
                else
                    return false;
            }            
        }
        return true;
    }
    
    int dfs(map<int,vector<string>> &m,string str,int len)
    {
        if(m.find(len+1)==m.end())
            return 1;
        
        vector<string> vec=m[len+1];
        
        if(visited.find(str)==visited.end())
            visited[str]=1;
        
        for(auto s:vec)
        {
            if(!isPoss(str,s))
                continue;
            
            
            int l;
            if(visited.find(s)==visited.end())
                l=dfs(m,s,len+1);
            else
                l=visited[s];
            visited[str]=max(visited[str],l+1);
            
            maxx=max(maxx,visited[str]);
        }
        return visited[str];
    }
    
    int longestStrChain(vector<string>& words) {
        maxx=1;
        int n=words.size();
        
        map<int,vector<string>> m;
        
        for(int i=0;i<n;i++)
        {
            m[words[i].size()].push_back(words[i]);
        }
             
        
        for(auto it:m)
        {
            int len=it.first;
            vector<string> vec=it.second;
            for(auto str:vec)
            {
                if(visited.find(str)!=visited.end())
                    continue;
                dfs(m,str,len);
            }
        }
        return maxx;
    }
};
