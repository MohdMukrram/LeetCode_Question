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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* t3 = dummy;
        int carry = 0;

        while(t1 != NULL && t2 != NULL){
            int value = (t1->val + t2->val + carry) % 10;
            carry = (t1->val + t2->val + carry) / 10;
            ListNode* node = new ListNode(value);
            t3->next = node;
            t3 = t3->next;
            t1 = t1->next;
            t2 = t2->next;

        }
        while(t1!=NULL){
            int value = (t1->val+ carry) % 10;
            carry = (t1->val + carry) / 10;
            ListNode* node = new ListNode(value);
            t3->next = node;
            t3 = t3->next;
            t1 = t1->next;
        }

        while(t2!=NULL){
            int value = (t2->val+ carry) % 10;
            carry = (t2->val + carry) / 10;
            ListNode* node = new ListNode(value);
            t3->next = node;
            t3 = t3->next;
            t2 = t2->next;
        }

        if(carry > 0){
            ListNode* node = new ListNode(carry);
            t3->next = node;
            t3 = t3->next;
            
        }

        return dummy->next;
    }
};