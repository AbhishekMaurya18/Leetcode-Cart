bool cmp(pair<char,int>& a,pair<char,int>& b) 
{ 
    return a.second > b.second; 
} 
class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(char c : s)m[c]++;
        vector<pair<char,int>>v;
        for(auto& it : m)v.push_back(it);
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(auto pai : v){
            for(int i=0;i<pai.second;i++){
                ans+=pai.first;
            }
        }
        return ans;
    }
};