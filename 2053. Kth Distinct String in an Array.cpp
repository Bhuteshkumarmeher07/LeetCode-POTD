class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> cnt;
        for(auto & str: arr){
            cnt[str]++;
        }
        for(auto & str: arr){
            if(cnt[str] == 1){
                k--;
                if(k == 0) return str;
            }
        }
        return "";
    }
};
