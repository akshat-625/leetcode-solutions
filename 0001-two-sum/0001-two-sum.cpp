
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // // TC = O(N^2)

        // // unordered map<int,int>ans;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] == target)
        //             return {i, j};
        //     }
        // }
        // return {};



//TC=O(N)

unordered_map<int,int> ans;

for( int i=0; i<n; i++) {
    int need = target - nums[i];

if( ans.count(need)){
    return {ans[need],i};  // here key = need, value = i // because we need i in the answer; also ans[key] is the pointer 
}

ans[nums[i]] = i;  //just key pointing to its value because  i is asked in the question

}
return {};

    }
};

