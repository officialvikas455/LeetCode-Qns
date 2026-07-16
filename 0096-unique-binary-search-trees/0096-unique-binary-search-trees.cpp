class Solution {
public:
 int solveMem(int n, vector<int> &dp){
    if(n <= 1) return 1;
    
     int ans = 0;

     for(int i=1; i<=n; i++){
        ans += solveMem(i-1,dp) * solveMem(n-i,dp);
     }
     return dp[n] = ans;
 }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return solveMem(n, dp);
    }
};