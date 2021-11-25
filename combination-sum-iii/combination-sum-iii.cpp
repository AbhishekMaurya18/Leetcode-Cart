class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n or n>45)
            return {};
        vector<vector<int>> res;
        //vector<int> candidates={1,2,3,4,5,6,7,8,9};
        combination(res,1,n,k,{});
        return res;
    }
    void combination(vector<vector<int>>&res,int start,int target,int k,vector<int> cur)     {
        if(target==0 && k==0){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<=9;++i){
            if(target<i or k<0)
                break;
            cur.push_back(i);
            combination(res,i+1,target-i,k-1,cur);
            cur.pop_back();
            
        }
        
    }
        
};