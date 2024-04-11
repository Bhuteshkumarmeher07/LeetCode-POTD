class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char> st;
        for(auto digit:num){
            if(k>0){
                while(!st.empty() && st.top() > digit)
                {
                    st.pop();
                    k--;
                    if(k==0){
                        break;
                    }
                }
            }
            st.push(digit);
        }
        // K ka value abhi b bachi hai toh
        if(k > 0)
        {
            while(!st.empty() && k)
            {
                st.pop();
                k--;
            }
        }
        // now, stack ko pop karke final ans bana lena chahiye
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // remove leading Zeros 
        // Ex -> 1 0 2 0 0, k=1
        // stack => 0 2 0 0 
        // ans => 0 2 0 0 
        while(ans.size() > 0 and ans.back() == '0'){
            ans.pop_back();
        }
        // get real ans
        reverse(ans.begin(), ans.end());
        // wrong ans at 1 0 , k = 2 , ans = ""
        if(ans == ""){
            return "0";
        }
        else{
            return ans;
        }
        //return ans;
    }
};
