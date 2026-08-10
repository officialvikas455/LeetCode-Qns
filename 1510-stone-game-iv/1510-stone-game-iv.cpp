class Solution {
public:
vector<int> t;
    bool solve(int n){
        if(n==0) 
        return false;

        if(t[n] != -1) return t[n];

        for(int i=1; i*i <= n; i++){
            if(solve(n-i*i) == false){ // for Bob looses
                return t[n] = true; // alice jeet gyi
            }
        }
        return t[n] = false;
    }
   
    bool winnerSquareGame(int n) {
        t.assign(n+1,-1);
      return solve(n); // Yeh Alice ke liye h agr yeh true h to alice wins , else looses;
    }
};