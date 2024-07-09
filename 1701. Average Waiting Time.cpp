class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long busyUptil = 0;
        long n = customers.size();
        long waitingTime = 0;
        for(int i=0; i<n; i++){
            long arrival = customers[i][0];
            long time = customers[i][1];
            waitingTime += (max(arrival, busyUptil) + time - arrival);
            busyUptil = max(arrival, busyUptil) + time;
        }
        return (waitingTime * 1.0)/n;
    }
};
