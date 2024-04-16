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
        ListNode *curA = headA , *curB = headB ;
        
        if ( headA == NULL || headB == NULL )
            return NULL ;
    
        while ( curA != curB )
        {
            
            curA = curA->next ;
            curB = curB->next ;
            
            if ( curA == curB )
                return curA ;
            
            
            if ( curA == NULL )
                curA = headB ;
            
            if ( curB == NULL )
                curB = headA ;
            
        }
        return curA ;
    }
};