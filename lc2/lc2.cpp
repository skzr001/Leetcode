/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//what if the two numbers contain any leading zero? A possible follow up? May be too easy!
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sentinel(0);
        ListNode *tail=&sentinel;
        for(int carry=0;carry||l1||l2;tail=tail->next){
            int sum=carry+(l1?l1->val:0)+(l2?l2->val:0);
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        return sentinel.next;
    }
};}