Question->
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]

Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]

Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
  

Code:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* delNodesUtil(TreeNode* &root,unordered_set<int> &sets,vector<TreeNode*> &ans)
    {
        if(!root)
            return NULL;
        if(sets.find(root->val)!=sets.end())
        {
            sets.erase(root->val);
            TreeNode* l=delNodesUtil(root->left,sets,ans);
            TreeNode* r=delNodesUtil(root->right,sets,ans);
            if(l)
                ans.push_back(l);
            if(r)
                ans.push_back(r);
            return NULL;
        }
        else
        {
            root->left=delNodesUtil(root->left,sets,ans);
            root->right=delNodesUtil(root->right,sets,ans);
            return root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> sets(to_delete.begin(),to_delete.end());
        if(sets.find(root->val)==sets.end())
            ans.push_back(root);                                                        //Has to be pushed in the beginning itself if it is valid
        
        delNodesUtil(root,sets,ans);                                                    //root has to be passed by reference for the sake of the case where root is already pushed into ans but it's children might get rejected in final tree.
        return ans;
    }
};
 
