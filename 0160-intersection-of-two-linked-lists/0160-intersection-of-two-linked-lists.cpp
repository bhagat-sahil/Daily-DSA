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
        unordered_map<ListNode*,int> mp ;
        
        ListNode *cur = headA ;
        
        while ( cur != NULL )
        {
            mp[cur]++ ;
            cur = cur->next ;
        }
        
        cur = headB ;
        while ( cur != NULL )
        {
            if ( mp.find(cur) != mp.end() )
                return cur ;
            cur = cur->next ;
        }
        return NULL ;
        
    }
};