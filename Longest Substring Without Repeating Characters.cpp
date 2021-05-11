Question->
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

  Topics-> 2 pointers, hashing

Code:

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,n=s.size(),len=0;
        map<char,int> count;
        
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(count.find(ch)==count.end())
            {
                count[ch]++;
            }
            else
            {
                count[ch]++;
                while(start<=i && count[ch]>1)
                {
                    count[s[start]]--;
                    start++;
                }
            }
            len=max(len,i-start+1);
        }
        return len;
    }
};


