class Solution {
public:
    bool canAliceWin(int n) {
        int st = 10;
        int steps = 0;
        while(n >= st){
            n -= st;
            st--;
            steps++;
        }
        return (steps % 2 == 1) ? true : false;
    }
};