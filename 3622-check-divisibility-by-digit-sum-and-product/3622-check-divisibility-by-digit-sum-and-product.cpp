class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int temp = n;
        int prod = 1;

        while(temp){
            int dig = temp%10;
            sum += dig;
            prod = prod * dig;
            temp /=10;
        }

        if(sum + prod == 0) return false;


       return n % (sum + prod) == 0;
    }
};