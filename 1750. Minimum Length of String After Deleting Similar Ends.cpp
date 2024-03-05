class Solution {
public:
    int minimumLength(string s) {
       int n=s.size();
       int i=0,j=n-1;
       while(i<j&&s[i]==s[j]){
           if(s[i]!=s[j]) break;
           while(s[i]==s[i+1]&&i+1<j){
               i++;
           }
           while(s[j]==s[j-1]&&i<j-1){
               j--;
           }
           i++;j--;
       } 
       return j-i+1;
    }
};
