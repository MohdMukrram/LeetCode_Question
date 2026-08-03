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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* d = dummy;

        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                d->next = t1;
                t1 = t1->next;
            }
            else{
                d->next = t2;
                t2 = t2->next;
            }
            d = d->next;
        }
        if(t1 != NULL){
            d->next = t1;
        }
        if(t2 != NULL){
            d->next = t2;
        }
        return dummy->next;
    }
};