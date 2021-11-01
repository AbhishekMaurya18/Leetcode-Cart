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
    int goodNodes(TreeNode* root) {
       
        return dfs(root,-10000);
        
    }
    int dfs(TreeNode* root, int m){
        if(!root){
            return 0;
        }
        int ans=root->val>=m?1:0;
        ans+=dfs(root->left,max(root->val,m));
        ans+=dfs(root->right,max(root->val,m));
        return ans;
    }
};