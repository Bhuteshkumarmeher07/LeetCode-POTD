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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode*temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int cnt=len-n;

        
        temp=head;
       if(cnt==0)
       return head->next;

        while(cnt>1 && temp->next!=NULL){
          
            temp=temp->next;
            cnt--;
        }
    
        if(temp->next!=NULL)
        temp->next=temp->next->next;
        
        return head;
    }
};
