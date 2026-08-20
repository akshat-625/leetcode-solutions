class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n=strs.size();
        
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[n-1];
        string res = "";
        
        for (int i = 0; i < strs[0].length(); i++) {
            if (first[i] == last[i]) {
                res += first[i];
            } 
            else break;
        
        }
        
        return res;
    }
};
