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
    int ans=0;
    int sumNumbers(TreeNode* root) {
        if(!root){
            return ans;
        }
        dfs(root,root->val);
        return ans;
    }
    
    void dfs(TreeNode* root, int res){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            ans+=res;
            return;
        }
        if(root->left)
            dfs(root->left,res*10+root->left->val);
        if(root->right)
            dfs(root->right,res*10+root->right->val);
    }
};