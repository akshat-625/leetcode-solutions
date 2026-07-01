class Solution {
public:
    bool isHappy(int n) {
        if (n < 10) return (n == 1 || n == 7);
        
        while(n != 1 && n != 4){
            int op=0;
            while(n > 0){
                int digit = n % 10;
                op += digit * digit;
                n = n / 10;
            }
            n=op;
        }
        
        return n==1;
    }
};
