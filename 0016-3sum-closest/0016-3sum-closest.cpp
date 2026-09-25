class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // int i = nums[0];
        // int j = i+1;
        // int k = nums.length()-1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=nums[0]+nums[1]+nums[2];

        for(int i=0; i<n-2; i++){
            int j=i+1, k=n-1;
            

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum) < abs(target-res)) res = sum;

                if (sum == target) return target;
                else if (sum < target) j++;
                else k--;
            }

        }
        return res; 

    }
};