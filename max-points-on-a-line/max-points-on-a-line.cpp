class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int ans=0,n=points.size();
        
        for(int i=0;i<n;i++){
            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;
            
            for(int j=i+1;j<n;j++){
                if(points[j][0]==points[i][0] && points[j][1]==points[i][1]) {
                    
                    overlap++;
                    continue;
                }
                else if(points[j][0]==points[i][0]) vertical++;
                else {
                    
                    int a=points[j][0]-points[i][0], b=points[j][1]-points[i][1];
                    int gcd=GCD(a, b);
                    
                    a/=gcd;
                    b/=gcd;
                    
                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }
                localmax=max(vertical, localmax);
            }
            
            ans=max(ans, localmax+overlap+1);
        }
        
        return ans;
    }
    int GCD(int a, int b){
        return b==0?a:GCD(b,a%b);
    }
};