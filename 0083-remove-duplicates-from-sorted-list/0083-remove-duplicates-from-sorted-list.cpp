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
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL )
            return NULL ;
        
        ListNode *cur = head, *temp = head ;
        while ( cur != NULL  )
        {
            if( temp->val == cur->val )
            {
                cur = cur->next ;
            }
            else 
            {
                temp->next = cur ;
                temp = cur ;
                cur = cur->next ;
            }
        }
        temp->next = NULL ;
        return head ;
    }
};