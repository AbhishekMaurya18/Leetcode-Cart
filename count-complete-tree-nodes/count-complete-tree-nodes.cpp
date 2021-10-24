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
/*
1.If left sub tree height equals right sub tree height then,
    a. left sub tree is perfect binary tree
    b. right sub tree is complete binary tree
2.If left sub tree height greater than right sub tree height then,
    a. left sub tree is complete binary tree
    b. right sub tree is perfect binary tree
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left_depth=getcount(root->left);
        int right_depth=getcount(root->right);
        
        if(left_depth==right_depth){
            return pow(2,left_depth)+ countNodes(root->right);
        }
        else{
            return pow(2,right_depth)+ countNodes(root->left);
        }
    }
    
    //count depth of subtree O(log n)
    int getcount(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+getcount(root->left);
    }
};