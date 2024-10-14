class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;

        priority_queue<int> maxHeap;
        for(int num:nums){
            maxHeap.push(num);
        }

        while(k--){
            long long ele = maxHeap.top();
            maxHeap.pop();
            ans += ele;
            maxHeap.push(static_cast<int>(ceil(ele/3.0)));
        }
        return ans;
    }
};
