class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wset;
        bool isPresent=false;
        
        for(string word: wordList){
            if(endWord.compare(word)==0)
                isPresent=true;
            wset.insert(word);    //insert in set
        }
        
        if(!isPresent){
            return 0;   //endWord is not present in the set.
        }
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty()){
            depth++;
            int level_size=q.size();
            while(level_size>0){
                level_size--;
                string cur=q.front();
                q.pop();
                
                for(int i=0;i<cur.size();i++){
                    string temp=cur;
                    
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        
                        if(temp.compare(cur)==0)
                            continue;
                        else if(temp.compare(endWord)==0)
                            return depth+1;
                        else if(wset.find(temp)!=wset.end()){
                            q.push(temp);
                            wset.erase(temp);
                        }
                        
                    }
                }
            }
        }
        return 0;
    }
};