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
        ListNode* head = dummy;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val <= temp2->val){
                head->next = temp1;
                temp1=temp1->next;
                head=head->next;
            } else {
                head->next = temp2;
                temp2=temp2->next;
                head=head->next;
            }

            
        }
        while(temp1 != nullptr){
                head->next = temp1;
                temp1 = temp1->next;
                head=head->next;
            }

            while(temp2 != nullptr){
                head->next = temp2;
                temp2 = temp2->next;
                head=head->next;
            }

        return dummy->next;
    }
};