/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode sentinel(0);
        ListNode *tail=&sentinel;

        int dup=(head==NULL)?0:head->val+1;
        for(;head;head=head->next){
            if(head->val!=dup&&(head->next==NULL||(head->val!=head->next->val))){
                tail->next=head;
                tail=head;
            }
            dup=head->val;
        }
        tail->next=NULL;
        return sentinel.next;
    }
};}