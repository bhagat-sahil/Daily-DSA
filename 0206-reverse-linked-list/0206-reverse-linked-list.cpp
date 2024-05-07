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
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next )
            return head ;
        ListNode *cur = head, *prev = NULL, *n = head->next ; 
        
        while ( cur != NULL )
        {
            cur->next = prev ;
            prev = cur ;
            cur = n ;
            if ( cur )
                n = cur->next ;
        }
        return prev ;
    }
};