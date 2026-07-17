class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> adj[N];

        for (auto i : prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        vector<int> in(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto j : adj[i]) {
                in[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (in[i] == 0)
                q.push(i);
        }
        int c = 0;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            c++;
            for (auto i : adj[n]) {
                in[i]--;
                if (in[i] == 0)
                    q.push(i);
            }
        }
        if (c == N)
            return 1;
        return 0;
    }
};