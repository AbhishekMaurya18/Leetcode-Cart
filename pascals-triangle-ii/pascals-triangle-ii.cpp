class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> cur(2,1);
        
        if(r==0){
            return {1};
        }
        if(r==1)
            return cur;
        
        vector<vector<int>> ans;
        ans.push_back(cur);
        
        for(int i=2;i<=r;i++){
            cur.resize(i+1);
            cur[0]=cur[i]=1;
            
            for(int j=1;j<i;j++){
                cur[j]=ans.back()[j]+ans.back()[j-1];
            }
            ans.push_back(cur);
        }
        return ans.back();
    }
};