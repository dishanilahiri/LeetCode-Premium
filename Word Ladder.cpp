Question->

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
  
Topics-> BFS, DFS

Following solution is using BFS.
  
Code:

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        
        if(wordSet.find(endWord)==wordSet.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int step=1;
        
        while(q.size())
        {
            int s=q.size();
            while(s--)
            {
                string f=q.front();
                q.pop();
                
                if(f==endWord)
                    return step;
                
                int i=0;
                while(f[i])
                {
                    char ch=f[i];
                    for(int j=0;j<26;j++)
                    {
                        if((j+'a')==(ch-'a'))
                            continue;
                        
                        f[i]=j+'a';
                        if(wordSet.find(f)!=wordSet.end())
                        {
                            q.push(f);
                            wordSet.erase(f);  //important to erase used word from set because you have already explored all variations of this word after inserting it in queue once.
                        }
                    }
                    f[i]=ch;
                    i++;
                }
            }
            step++;
        }
        return 0;
    }
};
