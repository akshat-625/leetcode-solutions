class Solution {
public:
    int reverse(int x) {
        string a = to_string(x);

        if (x < 0) {
            std::reverse(a.begin() + 1, a.end());
        } else {
            std::reverse(a.begin(), a.end());
        }

        long long val = stoll(a);

        if (val > INT_MAX || val < INT_MIN)
            return 0;

        return (int)val;
    }
};
