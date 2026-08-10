class Solution {
public:
    int countEven(int num) {
        int SOD = 0, n = num;

        while(n){
            SOD += (n%10);
            n/=10;
        }

        return SOD % 2 ? (num-1)/2 : num/2;
    }
};