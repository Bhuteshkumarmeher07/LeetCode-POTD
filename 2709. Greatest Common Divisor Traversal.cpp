class Solution {
public:
    vector<int> primeFactors(int x) {
        vector<int> ans;

        for (int i = 2; i * i <= x; i++) {
            bool insert = true;
            while (x % i == 0) {
                x /= i;
                if (insert) {
                    ans.push_back(i);
                    insert = false;
                }
            }
        }

        if (x > 1)
            ans.push_back(x);

        return ans;
    }

    void dfs(unordered_map<int, set<int>>& graph, int node,
             unordered_map<int, bool>& vis) {
        vis[node] = true;

        for (int c : graph[node]) {
            if (vis.find(c) == vis.end()) {
                dfs(graph, c, vis);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        if (find(nums.begin(), nums.end(), 1) != nums.end())
            return false;

        unordered_map<int, set<int>> graph;
        unordered_map<int, bool> vis;
        unordered_set<int> nodes;
        int lastNode = -1;

        for (int num : nums) {
            vector<int> factors = primeFactors(num);
            int sz = (int)factors.size();

            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    int u = factors[i];
                    int v = factors[j];
                    nodes.insert(u);
                    nodes.insert(v);
                    if (i != j) {
                        graph[u].insert(v);
                        graph[v].insert(u);
                        lastNode = u;
                    }
                }
            }
        }

        dfs(graph, lastNode, vis);
        return nodes.size() == vis.size();
    }
};
