class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        int mx=0,count=0,identical=0;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
            if(mp[tasks[i]]>mx) mx=mp[tasks[i]];
        }       
        for(auto it:mp)
        {
            identical+=it.second;
            if(it.second==mx) count++;
        } 
        int res=( mx-1)*(n+1)+count;
        if(res<identical) return identical;
        else return res; 
    }
};
