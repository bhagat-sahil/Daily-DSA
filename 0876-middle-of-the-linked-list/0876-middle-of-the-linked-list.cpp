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
    ListNode* middleNode(ListNode* head) {
        if ( head->next == NULL )
            return head ;
        int count = 0 ;
        ListNode *cur = head ;
        while ( cur != NULL )
        {
            cur = cur->next ;
            count++ ;
        }
        count = count / 2 ;
        
        cur = head ;
        
        while (  count > 0 )
        {
            cur = cur->next ;
            count-- ;
        }
        return cur ;
    }
};