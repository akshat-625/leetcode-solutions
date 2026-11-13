class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j =0;
        int cur=0;
        int lengths=INT_MAX;
        
        for(int i=0; i<n; i++){
            cur+=nums[i];
        
        while(cur>=target){
            lengths = min(lengths,i-j+1);
            cur-=nums[j];
            j++;
        }
    }
    if (lengths == INT_MAX) return 0;
    return lengths;

    }

};