class Solution {
public:
    string longestPalindrome(string s) {
       if (s.length() <= 1) return s;
       int  n=s.length();
       int start=0;

       int max=1;
       
        for(int i=0;i<n;i++){
            int left=i;
            int right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                int curr=right-left+1;
                if(curr>max){
                    max=curr;
                    start=left;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                int curr=right-left+1;
                if(curr>max){
                    max=curr;
                    start=left;
                }
                left--;
                right++;
        }         
    }
        return s.substr(start,max);
    }
};