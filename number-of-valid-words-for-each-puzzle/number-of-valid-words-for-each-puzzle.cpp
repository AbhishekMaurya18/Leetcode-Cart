class Solution {
public:
    int makeMask(string word){
        int mask=0;
        for(char c: word){
            mask|=(1<<c-'a');
        }
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> mask_freq;
        vector<int> ans;
        
        for(auto word: words){
            mask_freq[makeMask(word)]++;
        }
        
        for(auto pw: puzzles){
            int mask=makeMask(pw),submask=mask,first=(1<<pw[0]-'a'),count=0;
            
            while(submask){
                if(submask & first){
                    count+=mask_freq[submask];
                }
                submask=(submask-1)& mask;
            }
            ans.push_back(count);
        }
        return ans;
    }
};