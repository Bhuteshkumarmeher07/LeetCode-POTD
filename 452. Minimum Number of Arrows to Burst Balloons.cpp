class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int temp = points[0][1];
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (points[i][0] <= temp) {
                temp = min(temp, points[i][1]);
            }
            else {
                temp = points[i][1];
                count++;
            }
        }
        
        return count;
    }
};
