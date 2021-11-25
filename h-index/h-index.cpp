class Solution {
public:
    int hIndex(vector<int>& cite) {
       sort(cite.rbegin(),cite.rend());
        int i=0;
        for(i=0;i<cite.size();i++){
            if(cite[i]<i+1){
                return i;
            }
        }
        return i;
    }
};