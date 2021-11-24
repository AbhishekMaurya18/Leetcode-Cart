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
    TreeNode* build(vector<int>& in,int x, int y, vector<int>& po, int a, int b){
        
        if(x>y || a>b){
            return NULL;
        }
        TreeNode* node= new TreeNode(po[a]);
        int index=x;
        while(po[a]!=in[index]){
            index++;
        }
        
        node->left= build(in,x,index-1,po,a+1,a+index-x);
        node->right= build(in,index+1,y,po,a+index-x+1,b);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return build(in,0,in.size()-1,pre,0, pre.size()-1);
    }
};