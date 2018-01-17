/*
Two pointer, slow and fast. If it has a circle, the two pointers will eventually meet.
Smart trick without using extra space.
*/
/*
1->2->3->2
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};