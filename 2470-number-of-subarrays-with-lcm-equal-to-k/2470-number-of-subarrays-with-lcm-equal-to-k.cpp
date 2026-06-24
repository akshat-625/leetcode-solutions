class Solution {
public:
    long long gcd(long long int a, long long int b)
     {
       if (b == 0) {
           return a;
           } else {
         return gcd(b, a % b);
      }
 }
      long long lcm(long long int a, long long int b)
      {
        return (a * b)/ gcd(a, b);
       }
  
    int subarrayLCM(vector<int>& nums, int k) {
    int cnt = 0;
        
    int n = nums.size();
        
        for(int i=0; i<n; i++){
            int c  = nums[i];

            for(int j=i; j<n; j++)
            {
                c = lcm(c, nums[j]);

                if(c == k){
                    cnt++;
                }
                if(c > k) break;
            }
        }
        return cnt;
    }
};