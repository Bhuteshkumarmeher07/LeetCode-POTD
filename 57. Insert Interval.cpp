class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0) return {newInterval};
        vector<vector<int>> ans;
        bool flag = false;
        for(int i=0;i<n;i++){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                if(!flag){
                    ans.push_back(newInterval);
                    flag = true;
                }
                ans.push_back(intervals[i]);
            }
            else{
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
        }
        if(!flag) ans.push_back(newInterval);
        return ans;
    }
};
