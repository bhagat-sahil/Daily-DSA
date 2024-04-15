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
        ListNode *slow = head, *fast = head ;
        ListNode *temp ;
        if ( head->next == NULL )
            return head ;
        while ( fast != NULL && fast->next != NULL )
        {
            slow = slow->next ;
            temp = fast->next ;
            fast = temp->next ;
        }
        return slow ;
    }
};