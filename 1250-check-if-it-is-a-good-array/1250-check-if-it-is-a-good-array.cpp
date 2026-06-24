class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
       int cur=nums[0];
       for(int i=1; i<nums.size(); i++ ) {
           cur=gcd(cur,nums[i]);
       }
       return(cur==1);
    }
    int gcd(int a,int b){
        if(b == 0) return a;
        else return gcd(b,a%b);
    }
    
};