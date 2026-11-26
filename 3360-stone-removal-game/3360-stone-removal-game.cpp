class Solution {
public:
    bool canAliceWin(int n) {
        int aliceRemove = 10;
        int aliceTurn = true;
        while(n >= aliceRemove){
            n -= aliceRemove;
            aliceRemove--;
            aliceTurn = !aliceTurn;
        }
        return !aliceTurn;
    }
};