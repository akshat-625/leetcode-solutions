class Solution {
    int solve(int n, int f, int remain, vector<vector<int>>& common, vector<int>& dp) {
        auto idx = f * (1 << n) + remain;
        if (remain == (1 << f)) {
            dp[idx] = 0;
            return 0;
        }
        if (dp[idx] >= 0) return dp[idx];
        int res = 0;
        remain ^= (1 << f);
        for (int i = 0; i < n; ++i) {
            if (remain & (1 << i)) {
                res = max(res, common[f][i] + solve(n, i, remain, common, dp));
            }
        }
        return dp[idx] = res;
    }
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> common(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int l = min(words[i].size(), words[j].size());
                    while (l > 0 && (words[i].substr(words[i].size() - l) != words[j].substr(0, l))) {
                        --l;
                    }
                    common[i][j] = l;
                }
            }
        }

        int len = (1 << n);
        vector<int> dp(n * len, -1);

        int most_c = -1;
        int remain = len - 1;
        int f_idx = 0;
        for (int i = 0; i < n; ++i) {
            auto tmp = solve(n, i, remain, common, dp);
            // cout << i << " with " << tmp << endl;
            if (most_c < tmp) {
                most_c = tmp;
                f_idx = i;
            }
        }

        // cout << f_idx << " " << most_c << endl;

        string res = words[f_idx];
        remain ^= (1 << f_idx);
        for (int i = 1; i < n; ++i) {
            for (int c = 0; c < n; ++c) {
                if ((remain & (1 << c)) && dp[c * len + remain] == (most_c - common[f_idx][c])) {
                    res += words[c].substr(common[f_idx][c]);
                    remain ^= (1 << c);
                    most_c -= common[f_idx][c];
                    f_idx = c;
                    // cout << "take " << c << " remain " << remain << "," << most_c << endl;
                    break;
                }
            }

        }
        return res;
    }
};