class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        int a=nums1.size();
        sort(nums1.begin(), nums1.end());

        if (a%2==0){
            return (nums1[a/2]+nums1[a/2-1])/2.0;
        }
        else return nums1[a/2];

        
    }
};