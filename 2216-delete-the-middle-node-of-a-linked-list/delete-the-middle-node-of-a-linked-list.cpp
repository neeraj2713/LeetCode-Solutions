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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL; 
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next){
            fast = fast->next;
            if(fast->next) fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = head;
        while(temp->next != slow){
            temp = temp->next;
        }

        temp->next = slow->next;
        slow->next = NULL;
        delete(slow);

        return head;
    }
};