Question->
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Topic-> BFS, Queue, Tree Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(q.size())
        {
            int n=q.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* f=q.front();
                q.pop();
                temp.push_back(f->val);
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};
