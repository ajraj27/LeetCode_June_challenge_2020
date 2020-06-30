class Solution {
public:
    int n,m;
    
    bool dfs(int i,int r,int c,string& s,vector<vector<char> >& board){
         if(i==s.length()) return true;
        if(r<0 || r>=n || c<0 || c>=m) return false;
       
        
        if(s[i]==board[r][c]){
            char ch=board[r][c];
            board[r][c]='#';
            bool z=dfs(i+1,r+1,c,s,board) || dfs(i+1,r-1,c,s,board) ||
                dfs(i+1,r,c+1,s,board) || dfs(i+1,r,c-1,s,board);
            
            board[r][c]=ch;
            return z;
        }
        
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        vector<string> res;
        for(auto s:words){
           for(int i=0;i<n;i++){
               bool flag=false;
                for(int j=0;j<m;j++){
                    if(s[0]==board[i][j]){
                        if(dfs(0,i,j,s,board)){
                            res.push_back(s);
                            flag=true;
                            break;
                            
                        } 
                    }
                }
               
               if(flag) break;
            }
        }
        
        return res;
        
        
    
        
        
    }
};
