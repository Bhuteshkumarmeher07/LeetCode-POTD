class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        for(auto it: order){
            if(mp.find(it)!=mp.end()){
                string st(mp[it],it);
                ans+=st;
                mp.erase(it);
            }
        }
        for(auto it:mp){
            string st(it.second,it.first);
            ans+=st;
        }
        return ans;
    }
};
