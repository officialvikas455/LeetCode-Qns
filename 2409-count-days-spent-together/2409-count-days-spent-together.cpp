class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


        auto toDay = [&](const string &s){
            int m = stoi(s.substr(0,2));
            int d = stoi(s.substr(3,2));

            int res = d;

            for(int i= 0; i<m-1; i++){
                res += days[i];
            }
            return res;
        };

        int startA = toDay(arriveAlice);
        int endA = toDay(leaveAlice);
        int startB = toDay(arriveBob);
        int endB = toDay(leaveBob);
        
        //find the overlap
        int startTogether = max(startA, startB);
        int endTogether = min(endA, endB);


        if(startTogether <= endTogether){
            return endTogether - startTogether + 1;
        }
        return 0;

    }
};