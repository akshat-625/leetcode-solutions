class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin() , nums.end());
        int n=nums.size();
        // unordered map<int,int>ans;
        for( int i=0; i<n; i++){
            for( int j=i+1; j<n; j++){
                if(nums[i] + nums[j] == target) return{i,j};
            }
        }
        return {};
    }
};