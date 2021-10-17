class Solution {
public:
    bool isHappy(int n) {
        map<int,int> m;
        m[n]=1;
        
        int prod=n;
        
        while(prod!=1){
            //cout<<prod<<" ";
            
            int sq=0;
            while(prod>0){
                sq+=pow((prod%10),2);
                prod/=10;
            }
            prod=sq;
            if(m.find(prod)!=m.end()){
                return false;
            }
            m[prod]++;
        }
        return true;
    }
};