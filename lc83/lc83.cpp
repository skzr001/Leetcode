/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {//so easy....
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode sentinel(head==NULL?0:head->val+1);
        ListNode *tail=&sentinel;

        for(;head;head=head->next) {
            if(head->val!=tail->val) {
                tail->next=head;
                tail=head;
            }
        }
        tail->next=NULL;
        return sentinel.next;
    }
};}