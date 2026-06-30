#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        const char* str = s.c_str();
        char* end;
        long long val = strtol(str, &end, 10); // base 10

        if (val < INT_MIN) return INT_MIN;
        if (val > INT_MAX) return INT_MAX;
        return (int)val;
    }
};
