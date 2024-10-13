class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int,int>> v;
        for(int i=0; i<k; i++){
            for(auto it: nums[i]){
                v.push_back({it,i+1});
            }
        }

        sort(v.begin(), v.end());

        int n = v.size();
        int l=0, r=-1;
        map<int,int> mp;

        int range = INT_MAX;
        vector<int> ans(2);
        while(r<n){
            while(r<n && mp.size()<k){
                ++r;
                if(r==n) break;
                mp[v[r].second]++;
            }
            if(r>=n) break;

            if(abs(v[r].first-v[l].first) < range){
                range = v[r].first-v[l].first;
                ans = {v[l].first, v[r].first};
            }
            
            if(--mp[v[l].second]==0){
                mp.erase(v[l].second);
            }
            ++l;
        }

        return ans;
    }
};
