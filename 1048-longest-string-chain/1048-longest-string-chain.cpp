class Solution {
public:
static bool comp(string words1, string words2){
    return words1.size() < words2.size();
}
 bool isPre(string words1,string words2){
     if(words1.size()+1 != words2.size())
        return 0;

     int i = words1.size(), j = words2.size();


     while(i && j){
        if(words1[i-1] == words2[j-1]){
            i--; j--;
        }
        else{
            j--;
        }
     }

     return i == 0;

 }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(),comp);
        vector<int> LIS(n,1);
        int maxLen = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(isPre(words[j], words[i])){
                    LIS[i] = max(LIS[i], 1+LIS[j]);
                }
            }
            maxLen = max(maxLen, LIS[i]);
        }
        return maxLen;

        
    }
};