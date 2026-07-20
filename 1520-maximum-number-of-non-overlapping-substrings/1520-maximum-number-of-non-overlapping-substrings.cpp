class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;

        for (int c = 0; c < 26; c++) {

            if (first[c] == n) continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for (int i = l; i <= r; i++) {

                int ch = s[i] - 'a';

                if (first[ch] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if (valid)
                intervals.push_back({r, l});
        }

        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int prevEnd = -1;

        for (auto &[r, l] : intervals) {

            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};