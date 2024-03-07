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
    // // Method 1 --> 2 pass use 
    // int getlength(ListNode* head)
    // {
    //     int len = 0;
    //     ListNode* temp = head;

    //     while(temp != NULL){
    //         len++;
    //         temp = temp -> next;
    //     }
    //     return len;
    // }
    // ListNode* middleNode(ListNode* head) {
    //     int n = getlength(head);
    //     int position = n/2 + 1;
    //     ListNode* temp = head;
    //     while(position != 1){
    //         position--;
    //         temp = temp -> next;
    //     }
    //     return temp;
    // }

    // method 2 : Tortoise algo/ slow fast method
   ListNode* middleNode(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head; // n/2 + 1 will be the ans
    // ListNode* fast = head -> next; // if we want n/2 as an ans

    while(fast != NULL && slow != NULL)
    {
        fast = fast -> next; // move
        if(fast != NULL)
        {
            fast = fast -> next; // if not NULL then simply move 
            slow = slow -> next;
        }
    }
    return slow; // slow = mid
   }
};
