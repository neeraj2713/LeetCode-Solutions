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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        
        while(slow){
            if(curr->val != slow->val){
                return false;
            }
            
            slow = slow->next;
            curr = curr->next;
        }
        
        return true;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
};