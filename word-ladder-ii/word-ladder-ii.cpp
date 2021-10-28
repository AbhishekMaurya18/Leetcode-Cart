class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> wset;
        unordered_set<string> visited;
        
        for(string word: wordList){
            wset.insert(word);    //insert in set
        }
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        while(!q.empty()){
            int level_size=q.size();
            while(level_size>0){
                level_size--;
                vector<string> path=q.front();
                q.pop();
                
                string cur=path.back();
                for(int i=0;i<cur.size();i++){
                    string temp=cur;
                    
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        
                        if(temp.compare(cur)==0)
                            continue;
                        if(wset.find(temp)!=wset.end()){
                            vector<string> news=path;
                            news.push_back(temp);
                            visited.insert(temp);
                            if(temp.compare(endWord)==0){
                                ans.push_back(news);
                            }
                            else
                                q.push(news);
                        }
                        
                    }
                }
            }
            for(auto& str : visited)
                    wset.erase(str);
        }
        return ans;
    }
};