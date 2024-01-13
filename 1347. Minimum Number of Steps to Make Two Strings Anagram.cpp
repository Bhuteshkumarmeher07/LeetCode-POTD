class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount(26,0),tCount(26,0);
        for(int i=0;i<s.size();i++){
            sCount[s[i]-'a']++;
            tCount[t[i]-'a']++;
        }
        int Result=0;
        for(int i=0;i<26;i++){
            Result+=abs(sCount[i]-tCount[i]);
        }
        return Result/2;
    }
};
