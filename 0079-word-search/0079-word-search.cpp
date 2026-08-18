class Solution {
    bool dfs(int r, int c, int i, vector<vector<char>>& board, const string& word){
        if(i == word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() 
            || board[r][c] == '#' || board[r][c] != word[i]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        if (dfs(r - 1, c, i + 1, board, word) ||
            dfs(r + 1, c, i + 1, board, word) ||
            dfs(r, c - 1, i + 1, board, word) ||
            dfs(r, c + 1, i + 1, board, word)) return true;
        
        board[r][c] = temp;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        unordered_map<char, int> boardletter;
        unordered_map<char, int> wordletter;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                boardletter[board[r][c]] += 1;
            }
        }
        for(int idx : word) wordletter[idx]++;
        for(auto& pair : wordletter) {
            if(boardletter[pair.first] < pair.second) return false;
        }
        if(boardletter[word[0]] > boardletter[word.back()]) {
            reverse(word.begin(), word.end());
        }
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == word[0]){
                    if(dfs(r, c, 0, board, word)) return true;
                }
            }
        }
        return false;
    }
};