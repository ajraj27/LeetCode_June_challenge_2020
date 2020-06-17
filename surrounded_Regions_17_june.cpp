class Solution {
public:
    
    void dfs(int x,int y,int n,int m,vector<vector<char>>& board){
        if(x<0 || y<0 || x>(n-1) || y>(m-1) || board[x][y]!='O') return;
        
        board[x][y]='#';
        
        dfs(x,y+1,n,m,board);
        dfs(x,y-1,n,m,board);
        dfs(x+1,y,n,m,board);
        dfs(x-1,y,n,m,board);

        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        if(n==0) return;
        int m=board[0].size();
        
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') dfs(0,i,n,m,board);
            if(board[n-1][i]=='O') dfs(n-1,i,n,m,board);
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,n,m,board);
            if(board[i][m-1]=='O') dfs(i,m-1,n,m,board);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
        
        
    }
};