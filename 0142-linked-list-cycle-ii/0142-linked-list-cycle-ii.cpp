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
    ListNode *detectCycle(ListNode *head) {
        
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode *slow = head, *fast = head, *start = head ;
        
        
        while ( fast != NULL && fast->next != NULL )
        {
            slow = slow->next ;
            fast = fast->next->next ;
            
            if ( slow == fast )
            {
                while ( slow != start )
                {
                    slow = slow->next ;
                    start = start->next ;
                }
                return start ;
            }
        }
        return NULL ;
    }
};