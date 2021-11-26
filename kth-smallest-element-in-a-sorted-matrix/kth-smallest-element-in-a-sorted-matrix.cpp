class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //Binary search 
        int n=matrix.size(),m=matrix[0].size();
        int lo = matrix[0][0], hi = matrix[n-1][m-1] + 1;//[lo, hi)
       
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0,  j =m-1;
            for(int i = 0; i < n; i++) {
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo; 
    }
};