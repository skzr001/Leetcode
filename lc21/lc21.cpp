/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//merge by iteration
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode sentinel(0);//sentinel initialization
        ListNode *tail=&sentinel;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1==NULL) tail->next=l2;
        else if(l2==NULL) tail->next=l1;
        return sentinel.next;
    }
};
===========================

class Solution {//merge by recursion
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val<l2->val) l1->next=mergeTwoLists(l1->next,l2);
        else l2->next=mergeTwoLists(l1,l2->next);
    }
};}