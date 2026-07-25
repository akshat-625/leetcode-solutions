class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> arr(s.size()+1);
        arr[0] = true;

        for (int i = 0; i < arr.size()-1; ++i) {
            if (!arr[i]) continue;

            for (string& word : wordDict) {
                if (i + word.size() - 1 < s.size() && word == s.substr(i, word.size()))
                    arr[i + word.size()] = true;
            }
        }

        return arr[s.size()];
    }
};