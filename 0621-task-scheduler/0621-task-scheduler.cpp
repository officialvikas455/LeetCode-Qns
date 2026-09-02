class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        priority_queue<int> maxHeap;

        // Count frequency
        for(char c : tasks) {
            freq[c]++;
        }

        // Put frequencies into max heap
        for(auto &x : freq) {
            maxHeap.push(x.second);
        }

        int time = 0;

        while(!maxHeap.empty()) {

            vector<int> temp;

            // One cycle = n + 1
            for(int i = 0; i <= n; i++) {

                if(!maxHeap.empty()) {
                    int f = maxHeap.top();
                    maxHeap.pop();

                    f--;

                    if(f > 0) {
                        temp.push_back(f);
                    }
                }

                time++;

                // Nothing left to process
                if(maxHeap.empty() && temp.empty()) {
                    break;
                }
            }

            // Put remaining frequencies back
            for(int f : temp) {
                maxHeap.push(f);
            }
        }

        return time;
    }
};