class Solution {
public:
    int minDistance(string a, string b) {
        vector<int> pre(b.size() + 1), cur(b.size() + 1);
        iota(pre.begin(), pre.end(), 0);
        for (int i = 1; i <= a.size(); i++) {
            cur[0] = i;
            for (int j = 1; j <= b.size(); j++) {
                cur[j] = (a[i - 1] == b[j - 1])
                    ? pre[j - 1]
                    : 1 + min({pre[j], cur[j - 1], pre[j - 1]});
            }
            pre = cur;
        }
        return pre.back();
    }
};