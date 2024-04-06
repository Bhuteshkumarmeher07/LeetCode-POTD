class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int i = 0 ;
        int n = s.length();
        stack<int>st;
        vector<int>valid( n +1 , 0 );
        while(i < n ){
            if(st.size() && s[st.top()] == '(' && s[i]==')'){
                  valid[st.top()] = 1;
                  valid[i]=  1;
                  st.pop();
            }
            else if( s[i] == '(') st.push(i);
            else if( s[i] != ')' && s[i] != '(')valid[i] = 1;
            ++i;
        }

        string ans = "" ;
        for( int i = 0  ; i<n ; ++i ){
           if(valid[i]) ans += s[i];
        }

        return ans;
    }
};
