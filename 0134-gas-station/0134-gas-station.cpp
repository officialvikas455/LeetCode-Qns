class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totGas = accumulate(begin(gas), end(gas), 0);
        int totalCost = accumulate(begin(cost), end(cost), 0);

        if (totGas < totalCost)
            return -1;

        int start = 0;
        int currGas = 0;

        for (int i = 0; i < n; i++) {
            currGas += (gas[i] - cost[i]);

            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }
        return start;
    }
};