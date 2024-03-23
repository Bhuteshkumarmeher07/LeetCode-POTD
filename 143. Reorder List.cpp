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
    ListNode* recursive(ListNode* first,ListNode* second){
        if(second == NULL) return first;
        ListNode* temp = recursive(first,second-> next);
        ListNode* temp2 = temp->next;
        temp->next = second;
        second->next = temp2;
        return temp2;
    }
    void reorderList(ListNode* head) {
        ListNode* pointer1 = head;
        ListNode* pointer2 = head;
        while(pointer2 != NULL && pointer2->next != NULL && pointer2->next->next!=NULL){
            pointer1 = pointer1->next;
            pointer2 = pointer2->next->next;
        }
        ListNode* temp = pointer1->next;
        pointer1->next = NULL;
        ListNode * k = recursive(head,temp);
    }
};
