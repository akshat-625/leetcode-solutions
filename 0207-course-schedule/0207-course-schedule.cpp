class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& visit, int i) {
        if (visit[i] == 2) return 0;
        if (visit[i] == 1) return 1;
        visit[i] = 1;

        for (auto j : adj[i]) {
            if (dfs(adj, visit, j))
                return true;
        }
        visit[i] = 2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        int m = pre.size();
        if (m < 2)
            return 1;
        vector<vector<int>> adj(n);
        for (const auto& i : pre) {
            adj[i[0]].push_back(i[1]);
        }
        bool a = 1;
        vector<int> visit(n, 0);
        for (int i = 0; i < n; i++) {
            if (visit[i] == 0 && dfs(adj, visit, i))  return false;
        }
        return true;
    }
};