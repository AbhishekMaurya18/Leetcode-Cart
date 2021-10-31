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
    int ans,pre;
    int getMinimumDifference(TreeNode* root) {
        
        if(!root){
            return ans;
        }
        pre=-1;
        ans=INT_MAX;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(!root)
            return;
        dfs(root->left);
        if(pre>=0){
           ans=min(ans,abs(pre-root->val)); 
        }
        pre=root->val;
        dfs(root->right);
        
    }
};