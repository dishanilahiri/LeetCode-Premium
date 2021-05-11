Question->

Given two strings s and t of lengths m and n respectively, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of English letters.

Topic-> Two Pointers

Explanation-> Basically, you need to grab a substring which has all the required characters. Once you have grabbed all characters, try to reduce length of substring by eliminating characters from the start of current substring.

Code:

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size() || !t.size() || !s.size())
            return "";
        
        map<char,int> ms,mt;
        for(auto it:t)
            mt[it]++;
        
        int start=0,n=s.size(),count=0,minn=n,minidx=-1;
        
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
                        
            if(mt.find(ch)!=mt.end() && mt[ch]>ms[ch])
                count++;
            ms[ch]++;
            
            if(count==t.size())
            {
                while((mt[s[start]] && ms[s[start]]>mt[s[start]]) || !mt[s[start]])
                {
                    if(mt[s[start]] && ms[s[start]]>mt[s[start]])
                    ms[s[start]]--;
                    
                    start++;
                }
                
                if(minn>=i-start+1)
                {
                    minn=i-start+1;
                    minidx=start;
                }
            }
        }
        
        if(minidx==-1)
            return "";
        
        return s.substr(minidx,minn);
    }
};
