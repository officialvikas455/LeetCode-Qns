class Solution {
public:
    int t[1001][1501];
    int n;
    int solve(int n,int budget, vector<vector<int>>& items,vector<int> &copies, int cheapestPrice){
        if(n==0){
            return budget/cheapestPrice;
        }
        if(budget == 0) return 0;
        if(t[n][budget] != -1){
            return t[n][budget];
        }
        int take = 0;
        int price = items[n-1][1];
        if(price <= budget){
            //take
            take = 1 + copies[n-1] + solve(n-1, budget-price, items, copies, cheapestPrice);
        }
        int skip = solve(n-1, budget, items, copies, cheapestPrice);

        return t[n][budget] = max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        vector<int> copies(n,0); //copies[i] = count of copies if I buy ith item
        int cheapestPrice = INT_MAX;

        for(int i=0; i<n; i++){
            cheapestPrice = min(cheapestPrice, items[i][1]);
            int copy = 0;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(items[j][0] % items[i][0] == 0){
                    copy++;
                }
                copies[i] = copy;
            }
        }

        memset(t, 0, sizeof(t));

        //base case

        for(int b=0; b <= budget; b++){
            t[0][b] = b /cheapestPrice;
        }

        for(int i=1; i<=n; i++){
            for(int b=0; b<=budget; b++){
                int price = items[i-1][1];
                int take = 0;
                if(price <= b){
                    take = 1 + copies[i-1] + t[i-1][b-price];
                }
                int skip = t[i-1][b];
                t[i][b] = max(take,skip);
            }
           
        }
        return t[n][budget];
        // return solve(n,budget,items,copies,cheapestPrice);
    }
};