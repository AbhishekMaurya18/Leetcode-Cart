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
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            if(root->left and root->right){
                TreeNode* temp;
                temp=root->left;
                root->left=root->right;
                root->right=temp;
            }
            else if (root->left){
                root->right=root->left;
                root->left=0;
            }
            else if(root->right){
                root->left=root->right;
                root->right=0;
            }
            
        invertTree(root->left);
        invertTree(root->right);
        }
     return root;
    }
};