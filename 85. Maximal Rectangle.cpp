class Solution {
private:
    vector<int> nextSmallestElement(int *height, int n) {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--) {
            int current = height[i];
            while (!st.empty() && st.top() != -1 && height[st.top()] >= current) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallestElement(int *height, int n) {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = 0; i < n; i++) {
            int current = height[i];
            while (!st.empty() && st.top() != -1 && height[st.top()] >= current) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n) {
        vector<int> prev = prevSmallestElement(heights, n);
        vector<int> next = nextSmallestElement(heights, n);
        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            if (next[i] == -1) {
                b = n - prev[i] - 1;
            }
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            area = max(area, largestRectangleArea(&heights[0], m));
        }
        return area;
    }
};
