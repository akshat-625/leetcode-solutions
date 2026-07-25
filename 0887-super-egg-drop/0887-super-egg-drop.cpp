class Solution {
public:
   vector<std::vector<int>> memo;

    int find(int k, int n) {
        if (n == 0 || n == 1) return n;
        if (k == 1) return n;

        if (memo[k][n] != -1) return memo[k][n];

        int ans = 1e6;
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int break_case = find(k - 1, mid - 1); 
            int survive_case = find(k, n - mid);   

            int temp = 1 + std::max(break_case, survive_case);
            ans = std::min(ans, temp);

            if (break_case > survive_case) {
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }

        return memo[k][n] = ans; 
    }

    int superEggDrop(int K, int N) {
        memo.resize(K + 1, std::vector<int>(N + 1, -1));
        return find(K, N);
    }
};
