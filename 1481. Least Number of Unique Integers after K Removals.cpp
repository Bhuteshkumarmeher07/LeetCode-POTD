struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int i : arr) freq[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(auto m : freq) pq.push({m.second, m.first});

        while(k){
            int freq = pq.top().first;
            cout << freq << " " << k << endl;
            if(freq <= k){
                pq.pop();
                k -= freq;
            } else {
                break;
            }
        }

        return pq.size();
    }
};
