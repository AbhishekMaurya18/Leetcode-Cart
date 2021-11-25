class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyer-Moore Voting Algorithm
        int count=0;
        int candidate;
        for(int n:nums){
            if(count==0)
                candidate=n;
            count+=(n==candidate)?1:-1;
        }
        return candidate;
        //TC-O(n)
        //SC-O(1)
    }
};