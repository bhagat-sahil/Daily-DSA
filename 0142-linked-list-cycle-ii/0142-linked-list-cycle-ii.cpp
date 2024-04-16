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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> mp ;
        
        ListNode *cur = head ;
        
        while( cur != NULL )
        {
            if ( mp.find(cur) != mp.end() )
                return cur ;
            
            mp[cur]++ ;
            cur = cur->next ;
            
        }
        return NULL ;
    }
};