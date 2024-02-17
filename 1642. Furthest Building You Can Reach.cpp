class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        for(int i=1;i<heights.size();i++){
            if(heights[i]<=heights[i-1])continue;
            bricks-=(heights[i]-heights[i-1]);
            q.push(heights[i]-heights[i-1]);
            if(bricks<0){
                if(ladders>0){
                    int t = q.top();
                    q.pop();
                    bricks+=t;
                    ladders-=1;
                }
                else{
                    return i-1;
                }
            }
        }
        return heights.size()-1;
    }
};
