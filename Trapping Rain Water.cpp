Question->

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105
  
Topic-> Two pointer

Explanation-> Main idea is kinda similar to the concept used in question "Container with most water" (check it's explanation and code here: https://github.com/dishanilahiri/LeetCode-Premium/blob/main/Container%20With%20Most%20Water.cpp).

Read the whole paragraph carefully to build a strong understanding.
Starting from the left side of array, you try to utilise a particular bar of height x. In order to do that, you have to find the largest bar to the right of this particular bar so that you can utilise it completely (i.e. store maximum amount of water possible with this particular bar).
So, for each i'th bar, you find a bar to it's right with greater or equal height and compute the water storage possible.

The catch now is that in doing just this, you'll be missing out on utilising those bars which are larger than any bar to it's right. eg. [5,0,0,2].
To accomodate these cases, you start viewing each bar from the right side of array and find a bar of greater height to it's left. 
                                                                                                      
NOTE: In 2nd iteration, we do not take measurements between bars of equal heights because it has already been taken care of in 1st iteration.

You can now write your own code based on above logic. Here's a code for reference.                                                                                                   
Code:
  
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> dpL(n,0),dpR(n,0);
        
        int i=0,j=0;
        while(i<n && height[i]==0)
            i++;
                
        while(i<n && j<n)
        {
            j=i+1;
            int c=0;
            while(j<n && height[i]>height[j])
            {
                c=1;
                j++;
            }
            //cout<<i<<" "<<j<<endl;
            int h=height[i];
            
            if(j!=n && c)
            {
                while(i<j)
                {
                    dpL[i]=h-height[i];
                    i++;
                }
                i--;
            }
            i++;
        }
        
        /*for(auto it:dpL)
            cout<<it<<" ";
        cout<<endl;*/
        
        i=n-1,j=n-1;
        while(i>=0 && j>=0)
        {
            j=i-1;
            int c=0;
            while(j>=0 && height[i]>=height[j])
            {
                c=1;
                j--;
            }
            //cout<<i<<" "<<j<<endl;
            int h=height[i];
            if(j>=0 && c)                                           Check var c is used to avoid infinite loop
            {
                while(i>j)
                {
                    dpR[i]=h-height[i];
                    i--;
                }
                i++;
            }
            i--;
        }
        
        /*for(auto it:dpR)
            cout<<it<<" ";
        cout<<endl;*/
        
        int ans=0;
        for(i=0;i<n;i++)
            ans+=(dpL[i]+dpR[i]);
        return ans;
    }
};
