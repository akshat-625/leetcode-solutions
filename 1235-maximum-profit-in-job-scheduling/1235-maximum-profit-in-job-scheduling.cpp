class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<tuple<int, int, int>> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> maxi(n, 0);
        vector<int> dp(n, 0);
        auto [x, y, z] = jobs[0];
        dp[0] = maxi[0] = z;
        for (int i = 1; i < n; i++) {
            auto [end, st, pr] = jobs[i];
            int s = 0, e = i - 1, mid;
            int ans = -1;
            while (s <= e) {
                mid = (s + e) / 2;
                auto [a, b, c] = jobs[mid];
                if (a > st)
                    e = mid - 1;
                else if (a <= st)
                    s = mid + 1, ans = mid;
            }
            if (ans >= 0)
                dp[i] = pr + maxi[ans];
            else
                dp[i] = pr;
            maxi[i] = max(maxi[i - 1], dp[i]);
        }
        return maxi[n - 1];
    }
};