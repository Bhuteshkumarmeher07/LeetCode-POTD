class Solution {
public:
    int openLock(vector<string>& de, string& target) {
        unordered_map<string, bool> deadend;
        unordered_map<string, int> explored;
        for (auto &i : de)
            deadend[i] = true;

        int ans = INT_MAX;
        queue<string> st;
        st.push("0000");
        while (!st.empty()) {
            string chk = st.front();
            int cnt = explored[chk];
            st.pop();

            if (chk == target) {
                return cnt;
            } else if (deadend.count(chk) > 0)
                continue;

            for (int i = 0; i < 4; i++) {
                int valu = chk[i] - '0';

                chk[i] = '0' + (valu + 1) % 10;

                if (explored.count(chk) == 0 && deadend.count(chk) == 0) {
                    explored[chk] = cnt + 1;
                    st.push(chk);
                }

                chk[i] = '0' + (valu + 9) % 10;
                if (explored.count(chk) == 0 && deadend.count(chk) == 0) {
                    explored[chk] = cnt + 1;
                    st.push(chk);
                }

                chk[i] = '0' + valu;
            }
        }
        if (ans < INT_MAX)
            return ans;
        return -1;
    }
};
