#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string concatenated = goal + goal;

        return concatenated.find(s) != string::npos;
    }
};