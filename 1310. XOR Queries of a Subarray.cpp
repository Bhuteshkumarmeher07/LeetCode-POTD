class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        // cumXor
        vector<int> cumXor(n, 0);
        cumXor[0] = arr[0];
        for(int i=1; i<n; i++){ // O(n)
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }
        vector<int> result;
        for(vector<int> query : queries){ // O(q)
            int left = query[0];
            int right = query[1];

            int xor_val = cumXor[right] ^ (left == 0 ? 0 : cumXor[left-1]);

            result.push_back(xor_val);
        }
        return result;

        // TC = O(n) + O(q)
        // SC = O(1)
    }
};
