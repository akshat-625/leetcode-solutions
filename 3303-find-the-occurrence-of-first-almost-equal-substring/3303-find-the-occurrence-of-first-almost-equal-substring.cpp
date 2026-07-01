class Solution {
public:
    vector<int> Zfun(string s){
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        z[0] = 0;
        for(int k=1;k<n;k++){
            if(k > r){
                 l = r = k;
                while(r < n && s[r] == s[r-l]){
                    r++;
                }
                z[k] = r - l;
                r--;
            }
            else{
                int k1 = k - l;
                if(z[k1] < r - k + 1){
                    z[k] = z[k1];
                }
                else{
                    l = k;
                    while(r  < n && s[r] == s[r-l]) r++;
                    z[k] = r - l;
                    r--;
                }
            }
        }

        return z;
    }
    int minStartingIndex(string s, string p) {
            int n = s.size();
            int m = p.size();
            vector<int> pref = Zfun(p + "$" + s);
            reverse(p.begin(), p.end());
            reverse(s.begin(), s.end());
            vector<int> suf = Zfun(p + "$" + s);


            for (int i = 0; i <=n-m; i++) {
                int prefix = min(pref[m + 1 + i], m);
                int rev_i  = n - (i + m);            
                int suffix = min(suf[m + 1 + rev_i], m);
                if (prefix + suffix >= m - 1)
                    return i;
            }
            return -1;
    }   
};