class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int st = 0;
        int end = 0;
        int maxLen = 0;
        unordered_map<int,int> basket;

        while(end < fruits.size()){
            basket[fruits[end]]++;


            while(basket.size() > 2){
                basket[fruits[st]]--;
                if(basket[fruits[st]] == 0) basket.erase(fruits[st]);
                st++;
            }
            maxLen = max(maxLen, end-st+1);
            end++;
        }
        return maxLen;
    }
};