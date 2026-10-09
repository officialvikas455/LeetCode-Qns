
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int openCnt = 0;
        int closeCnt = 0;

        // for (char ch : s) {
        //     if (ch == '(') {
        //         openCnt++;
        //     } else {
        //         closeCnt++;
        //     }
        // }

        int ans = 0;
        openCnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openCnt++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }

                if (openCnt > 0) {
                    openCnt--;
                } else {
                    ans++;
                }
            }
        }

        return ans + 2 * openCnt;
    }
};