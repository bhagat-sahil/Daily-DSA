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
    
    ListNode* reverse ( ListNode* head )
    {
        if ( head == NULL )
            return head ;
        ListNode *prev = NULL, *cur = head , *nxt = head->next ;
        
        
        while ( cur != NULL )
        {
            cur->next = prev ;
            prev = cur ;
            cur = nxt ;
            if ( cur )
                nxt = cur->next ;
        }
        return prev ;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if ( head->next == NULL )
            return head ;
        
        ListNode* from = head ;
        
        stack<ListNode*> st ;
        while ( from != NULL )
        {
            st.push(from) ;
            from = from->next ;
        }
            
       
        head = st.top() ;
        st.pop() ;
        
        from = head ;
        ListNode* temp = NULL ;
        
        while ( !st.empty())
        {
            temp = st.top() ;
            if ( temp->val >= from->val )
            {
                from->next = temp ;
                from = temp ;
            }
            st.pop() ;
        }
        from->next = NULL;
        return reverse(head);
    }
};