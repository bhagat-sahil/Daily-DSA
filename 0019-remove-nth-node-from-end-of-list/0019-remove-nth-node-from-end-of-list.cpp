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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if ( head == NULL )
            return NULL ;
        
        
        ListNode *cur = head ;
        int c = 0 ;
        while ( cur != NULL )
        {
            c++ ;
            cur = cur->next ;
        }
        if ( c == n )
            return head->next ;
        
        c = c - n ;
        cur = head ;
        while ( c > 1 )
        {
            cur = cur->next ;
            c-- ;
        }
        cur->next = cur->next->next ;
        
        return head ;
    }
};