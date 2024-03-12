/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            int sum = 0;
            int j = i;
            for(; j < n; j++){
                sum += arr[j];
                if(sum == 0){
                    for(int t = i; t <= j; t++) st.insert(t);
                    i = j+1;
                }
            }
        }
        vector<int> final;
        for(int i = 0; i < n; i++) if(st.find(i) == st.end()) final.push_back(arr[i]);
        if(final.size() == 0) return NULL;
        temp = head;
        for(int i = 0; i < final.size(); i++){
            temp->val = final[i];
            if(i != final.size()-1) temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};
