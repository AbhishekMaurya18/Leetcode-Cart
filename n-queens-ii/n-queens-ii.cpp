class Solution {
public:
    int count=0;
    int totalNQueens(int n) {
        vector<bool> column(4,false),dia1(6,false),dia2(6,false);
        count=0;
        searc(n,0,column,dia1,dia2);
        return count;
    }
    void searc(int n,int y,vector<bool> &column,vector<bool> &dia1,vector<bool> &dia2){
        if(y==n){
           count++;
            return; 
        }
        for(int x=0;x<n;x++){
            if(column[x]||dia1[x+y]||dia2[x-y+n-1])
                continue;
            column[x]=dia1[x+y]=dia2[x-y+n-1]=true;
            searc(n,y+1,column,dia1,dia2);
            column[x]=dia1[x+y]=dia2[x-y+n-1]=false;
        }
       
    }
};