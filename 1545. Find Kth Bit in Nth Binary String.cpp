#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    // Helper function to reverse a string
    string reverse(string s) {
        string rev = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            rev += s[i];
        }
        return rev;
    }

    // Helper function to invert a string
    string invert(string s) {
        string inv = "";
        for (auto c : s) {
            if (c == '0') inv += '1';
            else inv += '0';
        }
        return inv;
    }

    char findKthBit(int n, int k) {
        vector<string> ans;
        string s = "0";
        ans.push_back(s);

        // Generate the sequence
        for (int i = 1; i < n; i++) {
            string s = ans[i - 1] + "1" + reverse(invert(ans[i - 1]));
            ans.push_back(s);
        }

        // Return the kth character (0-based index) in the final string
        return ans[n - 1][k - 1];
    }
};
