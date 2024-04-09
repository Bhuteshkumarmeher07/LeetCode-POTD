class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int k_tickets = tickets[k]; // amount of tickets person 'k' wants to buy
        int time = k_tickets;       // buying his tickets will take 'k_tickets' time

        // goes through persons before person 'k'
        for (int i = 0; i < k; ++i) {
            // get the minimum of tickets available at the current person and person 'k'
            time += min(tickets[i], k_tickets);
        }

        // get the maximum possible number of tickets that people can buy after the person 'k'
        --k_tickets; 

        // goes through persons after person 'k'
        for (int i = k + 1; i < tickets.size(); ++i) {
            // get the minimum of tickets available at the current person and maximum possible
            time += min(tickets[i], k_tickets);
        }

        return time;
    }
};
