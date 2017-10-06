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
    ListNode* swapPairs(ListNode* head) {
        ListNode sentinel(0);
        ListNode *tail=&sentinel;

        while(head){
            ListNode *l1=head,*l2=l1->next;
            if(l2){
                head=l2->next;
                tail->next=l2;
                l2->next=l1;
            }
            else{// Wrong Answer. Because I use tail->next=l2 when l2 is actually doesn't exist.
                tail->next=head;
                head=NULL;
            }
            tail=l1;//the next 2 element to be considered
        }
        tail->next=NULL;
        return sentinel.next;
    }
};








}