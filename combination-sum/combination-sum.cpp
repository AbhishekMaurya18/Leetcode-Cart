class Solution {
public:
    vector<vector<int>> ans;
    vector<int> dummy;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dummy=candidates;
        
        vector<int> cur;
        solve(target,0,cur);
        
        return ans;
    }
    
    vector<vector<int>> solve(int target,int index,vector<int> &cur){
        if(target==0){
            ans.push_back(cur);
            return ans;
        }
        for(int i=index;i<dummy.size();i++){
            if(target>=dummy[i]){
                cur.push_back(dummy[i]);
                solve(target-dummy[i],i,cur);
                cur.pop_back();
            }
        }
        return ans;
    }
};