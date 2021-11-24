class Solution {
    vector<vector<int>> ans;
    vector<int> cur;
public:
    vector<vector<int>> combine(int n, int k) {
        
        solve(1,n,k);
        return ans;
    }
    
    void solve(int start,int end, int k){
        if(k==0){
            ans.push_back(cur);
            return;
        }
        
        for(int i=start;i<=end;i++){
            cur.push_back(i);
            solve(i+1,end,k-1);
            cur.pop_back();
        }
    }
};