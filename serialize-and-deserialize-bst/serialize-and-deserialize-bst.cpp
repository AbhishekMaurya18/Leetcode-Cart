/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        return to_string(root->val) + " "+ serialize(root->left)+ " " +serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return solve(s); 
    }
    TreeNode* solve(istringstream &s){
        string cur;
        
        getline(s,cur,' ');
        
        if(cur=="#")
            return NULL;
        TreeNode *root=new TreeNode(stoi(cur));
        root->left=solve(s);
        root->right=solve(s);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;