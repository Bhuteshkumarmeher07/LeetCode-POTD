class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        int start=0,i=0,anslen,mini=INT_MAX,ansindex,length=0;
        for(auto it:t)mp2[it]++;
        while(i<s.size()){
            mp1[s[i]]++;
            if(mp1[s[i]]<=mp2[s[i]]){
                length++;
            }
            if(length==t.length()){
                char temp=s[start];
                while(mp1[temp]>mp2[temp] or mp2[temp]==0){
                    if(mp1[temp]>mp2[temp]){
                        mp1[temp]--;
                    }
                    start++;
                    temp=s[start];                    
                }
                if((i-start)+1<mini){
                    mini=(i-start)+1;
                    ansindex=start;
                }
            }

            i++;

        }
        if(mini==INT_MAX){
            return "";
        }else{
            return s.substr(ansindex,mini);
        }
        
    }
};
