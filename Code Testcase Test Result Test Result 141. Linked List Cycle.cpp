/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // // Method 1 : using map
        // map<ListNode*, bool> table;
        // ListNode* temp = head;

        // while(temp != NULL)
        // {
        //     if(table[temp] == false){
        //         table[temp] == true;
        //     }
        //     else{
        //         // Cycle is present
        //         return true;
        //     }
        //     temp = temp -> next;
        // }
        // // loop is not present 
        // return false;
         

	    // Method 2 : Floyd cucle detection algo

		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
};
