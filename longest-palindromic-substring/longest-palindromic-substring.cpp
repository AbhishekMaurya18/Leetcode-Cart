class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        if(n<1){
            return "";
        }
        int start=0,end=0;
        
        for(int i=0;i<n;i++){
            int l1=expandByMiddle(s,i,i);
            int l2=expandByMiddle(s,i,i+1);
            int len=max(l1,l2);
            
            if(len>(end-start)){
                start=i-(len-1)/2;
                end=i+len/2;
            }
        }
        //cout<<start<<" "<<end;
        return s.substr(start,end-start+1);
    }
    
    int expandByMiddle(string s,int left, int right){
        if(left>right){
            return 0;
        }
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        
        return right-left-1;
    }
};