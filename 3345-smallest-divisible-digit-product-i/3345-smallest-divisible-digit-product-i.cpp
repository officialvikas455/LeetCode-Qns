class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            
            vector<int> dig;
            int temp = n;
            while(temp > 0){
                dig.push_back(temp%10);
                temp/=10;
            }

            int prod = 1;
            for(int i=0; i<dig.size(); i++){
                prod *= dig[i];
            }

            if(prod % t == 0){
                return n;
            }
            n++;
        }
    }
};