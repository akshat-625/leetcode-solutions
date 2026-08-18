class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>&vis, string &word, int idx)
    {
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]==1 || board[i][j]!=word[idx]) return false; 
        if (vis[i][j]==1 || board[i][j]!=word[idx]) return false;
        vis[i][j] = 1;
        bool ans = dfs(i,j-1,board,vis,word,idx+1) ||
                   dfs(i,j+1,board,vis,word,idx+1) ||
                   dfs(i-1,j,board,vis,word,idx+1) ||
                   dfs(i+1,j,board,vis,word,idx+1);
        vis[i][j] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m= board[0].size();
        char initial = word[0]; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==initial)
                {
                    vector<vector<int>>vis(n,vector<int>(m,0));
                    if(dfs(i,j,board,vis,word,0)==true) return true;
                }
            }
        }
        return false;
    }
};