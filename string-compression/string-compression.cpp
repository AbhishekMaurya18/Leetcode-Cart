class Solution {
public:
    int compress(vector<char>& chars) {
        int index_ans=0,n=chars.size(),index=0;
        
        while(index<n){
            int count=0;
            char c=chars[index];
            
            while(index<n && chars[index]==c){
                index++;
                count++;
            }
            chars[index_ans++]=c;
            if(count>1){
                string s=to_string(count);
                for(int i=0;i<s.size();i++){
                    chars[index_ans++]=s[i];
                }
            }
        }
        //cout<<ans<<"\n";
        return index_ans;
    }
};