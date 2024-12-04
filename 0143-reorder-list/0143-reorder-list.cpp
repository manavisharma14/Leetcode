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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return; // No need to reorder if the list has 0 or 1 node
        }

        // Step 1: Find the middle of the list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast pointer two steps and slow pointer one step each time
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // At this point, slow is at the middle of the list

        // Step 2: Reverse the second half of the list
        ListNode* secondHalfStart = slow->next; // Start of second half
        slow->next = nullptr; // Split the list into two halves

        ListNode* prev = nullptr;
        ListNode* curr = secondHalfStart;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // Store the next node
            curr->next = prev; // Reverse the current node's pointer
            prev = curr; // Move prev forward
            curr = nextNode; // Move curr forward
        }

        // Now, prev points to the head of the reversed second half
        ListNode* secondHalf = prev;
        ListNode* firstHalf = head;

        // Step 3: Merge the two halves
        while (secondHalf != nullptr) {
            ListNode* temp1 = firstHalf->next; // Store next node of first half
            ListNode* temp2 = secondHalf->next; // Store next node of second half

            firstHalf->next = secondHalf; // Link first node of first half to first node of second half
            secondHalf->next = temp1; // Link first node of second half to the next node of first half

            // Move pointers forward
            firstHalf = temp1;
            secondHalf = temp2;
        }

        // The list is now reordered in-place
    }
};
