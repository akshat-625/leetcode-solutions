class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0;
        int j=0;

        while(i < v1.size() || j<v2.size()){
            int num1 = 0, num2 = 0;

            while(i < v1.size() && v1[i] != '.'){
                num1 = num1*10 + (v1[i] - '0');
                i++;
            }
            while(j < v2.size() && v2[j] != '.'){
                num2 = num2*10 + (v2[j] - '0');
                j++;
            }

            if(num1 > num2) return 1;
            if(num1 < num2) return -1;

            i++;
            j++;
        }

        return 0;
    }
};