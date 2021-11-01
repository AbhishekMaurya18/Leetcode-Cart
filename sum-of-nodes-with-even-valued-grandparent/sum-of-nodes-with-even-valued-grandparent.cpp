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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        if(!root)
            return ans;
       
        queue<TreeNode*> q;
        q.push(root);
        //int level=-1;
        
        while(!q.empty()){
            //level++;
            int size=q.size();
            while(size--){
                TreeNode* node=q.front();
                q.pop();
               
                if(node->left){
                    if(node->left->left && node->val%2==0){
                        ans+=node->left->left->val;
                    }
                    if(node->left->right && node->val%2==0){
                        ans+=node->left->right->val;
                    }
                    q.push(node->left);
                }           
                if(node->right){
                    if(node->right->left && node->val%2==0){
                        ans+=node->right->left->val;
                    }
                    if(node->right->right && node->val%2==0){
                        ans+=node->right->right->val;
                    }
                    q.push(node->right);
                }
                
            }
            
        }
        return ans;
    }
};