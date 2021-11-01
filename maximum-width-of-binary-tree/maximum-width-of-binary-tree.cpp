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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int ans=1;
        
        while(!q.empty()){
            int size=q.size(),l=q.front().second,r=l;
            
            while(size--){
                TreeNode* root=q.front().first;
                r=q.front().second;
                q.pop();
                
                if(root->left)
                    q.push({root->left,(r-l)*2});
                    
                if(root->right)
                    q.push({root->right,(r-l)*2+1});
                    
                }
                ans=max(ans,r-l+1);
            }
        return ans;
    }
};