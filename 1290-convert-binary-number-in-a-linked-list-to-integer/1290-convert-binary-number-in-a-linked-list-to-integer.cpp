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
    int getDecimalValue(ListNode* head) {
        
        string num = "" ;
        
        ListNode *cur = head ;
        while ( cur != NULL )
        {
            num = num + to_string( cur->val ) ;
            cur = cur->next ;
        }
        int p = 0 ;
        
        int ans = 0 ;
        
        for ( int i = num.size()-1 ; i >= 0 ; i-- )
        {
            ans = ans + pow(2,p)*(num[i]-'0') ;
            p++ ;
        }
        return ans ;
    }
};





















