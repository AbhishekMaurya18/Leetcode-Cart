class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int q=nums.size()-1,p=q-1;
        while(0<=p && nums[p]>=nums[q]){
            p--;
            q--;
        }
        if(p<0){
            sort(nums.begin(),nums.end());
            return ;
        }
        sort(nums.begin()+q,nums.end());
        while(nums[p]>=nums[q]){
            q++;
        }
        swap(nums[p],nums[q]);
        return ;
    }
};