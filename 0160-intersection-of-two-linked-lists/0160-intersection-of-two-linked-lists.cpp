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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        int a = 1, b = 1 ;
        ListNode *cur = headA ;
        
        while ( cur != NULL )
        {
            a++ ;
            cur = cur->next ;
        }
        
        cur = headB ;
        while ( cur != NULL )
        {
            b++ ;
            cur = cur->next ;
        }
        int increment = 0 ;
        
        ListNode *cur1 ;
        if ( a > b )
        {
            increment = a-b ;
            cur = headB ;
            cur1 = headA ;
            while ( increment-- )
            {
                cur1 = cur1->next ;
            }
        }
        else 
        {
            increment = b-a ;
            cur = headB ;
            cur1 = headA ;
            while ( increment-- )
            {
                cur = cur->next ;
            }
        }
        
        while ( cur != NULL && cur1 != NULL )
        {
            if ( cur == cur1 )
                return cur ;
            cur = cur->next ;
            cur1 = cur1->next ;
        }
        return NULL ;
    }
};