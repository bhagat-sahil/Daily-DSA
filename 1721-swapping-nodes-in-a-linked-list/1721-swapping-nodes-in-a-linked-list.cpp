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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur = head, *temp = head ;
        
        for ( int i = 1 ; i < k ; i++ )
            temp = temp->next ;
        
        int c = 0 ;
        while ( cur != NULL )
        {
            cur = cur->next ;
            c++ ;
        }
        
        c = c - k ;
        
        cur = head ;
        
        while ( c-- )
        {
            cur = cur->next ;
        }
        swap(temp->val,cur->val) ;
        return head ;
    }
};