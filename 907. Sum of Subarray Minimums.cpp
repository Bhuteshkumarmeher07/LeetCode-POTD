class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), M = 1e9 + 7;
        stack<int> st;
        vector<int> v1(n, 0), v2(n, 0);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) 
               st.pop();
            v1[i] = i - (!st.empty() ? st.top() : -1);
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
               st.pop();
            v2[i] = (!st.empty() ? st.top() : n) - i;
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (1LL * arr[i] * v1[i] * v2[i]) % M;
            ans %= M;
        }
        return ans % M;
    }
};
