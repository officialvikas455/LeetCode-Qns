// class Solution {
// public:
//     int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        
//         if(i == 0 || j == 0) return 0;

//         if(dp[i][j] != -1) return dp[i][j];

//         if(text1[i-1] == text2[j-1]) {
//             return dp[i][j] = 1 + f(i-1, j-1, text1, text2, dp);
//         } else {
//             return dp[i][j] = max(
//                 f(i-1, j, text1, text2, dp),
//                 f(i, j-1, text1, text2, dp)
//             );
//         }
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();

//         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

//         return f(n, m, text1, text2, dp);
//     }
// };





// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.size();
//         int m = text2.size();

//         // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//         vector<int> prev(m+1,0), curr(m+1,0);

//         for(int i = 1; i <= n; i++){
//             for(int j = 1; j <= m; j++){
//                 if(text1[i-1] == text2[j-1]){
//                    prev[j] = prev[j-1] + 1;
//                 } else {
//                     curr[j] = max(prev[j], curr[j-1]);
//                 }
//             }
//             prev = curr;
//         }

//         return prev[m];
//     }
// };





class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};