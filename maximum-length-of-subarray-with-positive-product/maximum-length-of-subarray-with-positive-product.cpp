class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> pos(n,0),neg(n,0);
        
        if(nums[0]>0){
            pos[0]=1;
        }
        
        if(nums[0]<0){
            neg[0]=1;
        }
        
        int res=pos[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i]>0){
                pos[i]=1+pos[i-1];
                if(neg[i-1]>0){
                    neg[i]=1+neg[i-1];
                }
                
            }
            else if(nums[i]<0){
                neg[i]=1+pos[i-1];
                if(neg[i-1]>0){
                    pos[i]=1+neg[i-1];
                }
            }
            res=max(res,pos[i]);
        }
        return res;
        
    }
};