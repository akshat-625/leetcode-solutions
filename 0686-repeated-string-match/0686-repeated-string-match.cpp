class Solution {
public:
    vector<int> getLps(string a) {
        vector<int> lps(a.size(), 0);
        int len = 0;
        int i = 1;
        while (i < a.size()) {
            if (a[i] == a[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if (len != 0)  len = lps[len - 1];
                else i++;
            }
        }
        return lps;
    }
    int repeatedStringMatch(string s, string p) {
        int n = ceil(p.size() / s.size()) + 2;
        cout << n << endl;
        bool found = false;
        vector<int> lps = getLps(p);
        int i = 0;
        int m = s.size();
        int j = 0;
        while (i < n * s.size()) {
            if (s[i % m] == p[j]) {
                i++;
                j++;
                if (j == p.size()) {
                    found = true;
                    break;
                }
            } 
            else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        if (!found) return -1;
        return ceil((i - 1) / m) + 1;
    }
};