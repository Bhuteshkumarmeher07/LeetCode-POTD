class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int present[100001] = {0};
        int matchesLost[100001] = {0};

        for(auto match : matches){
            present[match[0]] = 1;
            present[match[1]] = 1;
            matchesLost[match[1]]++;
        }
        vector<vector<int>>ans(2);
        for(int i=0; i<100001; i++){
            if(present[i]){
                if(matchesLost[i] == 0) ans[0].push_back(i);
                if(matchesLost[i] == 1) ans[1].push_back(i);
            }
        }
        return ans;
    }
};
