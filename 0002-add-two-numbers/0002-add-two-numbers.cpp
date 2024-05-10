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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1, *h2 = l2 ;
        int c = 0 ;
        ListNode * head = NULL, *cur = NULL ;
        while ( h1 != NULL && h2 != NULL )
        {
            ListNode *temp = new ListNode() ;
            if ( h1->val + h2->val + c > 9 )
            {
                temp->val = (h1->val + h2->val+c)%10 ;
                c = (h1->val + h2->val+ c)/10 ;
            }
            else 
            {
                temp->val = (h1->val + h2->val+c) ;
                c = 0 ;
            }
            if ( head == NULL )
            {
                head = temp ;
                cur = temp ;
            }
            else
            {
                cur->next = temp ;
                cur = temp ;
            }
            h1 = h1->next ;
            h2 = h2->next ;
            
        }
        
        while ( h1 != NULL )
        {
            if ( c == 0 )
            {
                cur->next = h1 ;
                cur = h1 ;
                h1 = h1->next ;
            }
            else 
            {
                ListNode *temp = new ListNode() ;
                temp->val = (h1->val +c)%10 ;
                c = (h1->val +c)/10 ;
                cur->next = temp ;
                cur = temp ;
                h1 = h1->next ;
            }
            
        }
        while ( h2 != NULL )
        {
            if ( c == 0 )
            {
                cur->next = h2 ;
                cur = h2 ;
                h2 = h2->next ;
            }
            else 
            {
                ListNode *temp = new ListNode() ;
                temp->val = (h2->val +c)%10 ;
                c = (h2->val +c)/10 ;
                cur->next = temp ;
                cur = temp ;
                h2 = h2->next ;
            }
        }
        if ( c == 1 )
        {
            ListNode * temp = new ListNode() ;
            temp->val = 1 ;
            cur->next = temp ;
            cur = temp ;
        }
        return head ;
    }
};