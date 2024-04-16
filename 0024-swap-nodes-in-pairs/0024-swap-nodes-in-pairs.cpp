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
    ListNode* swapPairs(ListNode* head) {
        
        if ( head == NULL || head->next == NULL )
            return head ;
        ListNode *temp = new ListNode() ;
        
        ListNode *prev = temp, *cur = head ;
        
        while ( cur != NULL && cur->next != NULL )
        {
            prev->next = cur->next ;
            cur->next = prev->next->next ;
            prev->next->next = cur ;
            prev = cur ;
            cur = cur->next ;
        }
        return temp->next ;
    }
};