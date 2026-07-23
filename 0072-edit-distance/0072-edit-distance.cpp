class Solution {
public:
    int f(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0) {
            return j + 1;
        }
        if (j < 0) {
            return i + 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = f(s1, s2, i - 1, j - 1, dp);
        } else {
            dp[i][j] = 1 + min(f(s1, s2, i - 1, j, dp),
                               min(f(s1, s2, i - 1, j - 1, dp),
                                   f(s1, s2, i, j - 1, dp)));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return f(word1, word2, word1.size() - 1, word2.size() - 1, dp);
    }
};