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
    ListNode* getmiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL) {
            fast = fast ->next;
            if(fast->next != NULL) {
                fast = fast -> next;
                slow = slow -> next;
            }
        }

        return slow;
    }
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr) {
        //base case
        if(curr == NULL) {
            return prev;
        }
        //1 case hum solve krenge
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //baaaki kon sambhalega - recursion
        return reverseUsingRecursion(prev, curr);
    }    
    bool compareList(ListNode* head1, ListNode* head2) {
        while( head2 != NULL) {
            if(head1 -> val != head2->val) {
                return false;
            }
            else {
                head1 = head1->next;
                head2=head2->next;
            }
        }
        return true;
    }    
    bool isPalindrome(ListNode* head) {
        // Step 1 : Break into 2 halfs
        ListNode* midNode = getmiddleNode(head);
        ListNode* head2 = midNode -> next;
        midNode -> next = NULL;
        // Step 2 : Reverse the 2nd halfs
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);
        // Step 3 : Compare both the ll
        bool ans = compareList(head, head2);
        return ans;
    }
};
