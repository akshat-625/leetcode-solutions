class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n= nums.size();
        if(n<=1) return n;    
        sort(nums.begin(),nums.end());
       int count =1;
       int maxi =1;

       for(int i=0; i<n-1; i++){
        if(nums[i] == nums[i+1]) continue;
        else if(nums[i]+1 == nums[i+1]) 
            count+=1;
        else {
            maxi=max(maxi,count);
            count =1;             //reset the counter if another mpre consecutive sequence is formed
        }
       } 
       maxi = max(maxi, count);
        return maxi;
       
    }
    // return 0;
     
};