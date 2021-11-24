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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int mid=n/2;
        if(n==0)
            return 0;
        TreeNode *node=new TreeNode(nums[mid]);
        //vector Slicing
        vector<int> num1=vector(nums.begin(),nums.begin()+mid);
        vector<int> num2=vector(nums.begin()+mid+1,nums.end());
        node->left=sortedArrayToBST(num1);
        node->right=sortedArrayToBST(num2);
        return node;
    }
};