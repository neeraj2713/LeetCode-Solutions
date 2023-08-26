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
    int getLength(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* reverseK(ListNode* &head, int k, int len){
        //base case
        if(head == NULL || head->next == NULL || k==1 || len < k) return head;

        //reverse first k nodes
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL; 
        int count = 0;

        while(curr != NULL && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        //recursion call
        if(forward != NULL){
            head->next = reverseK(forward, k, (len-k));
        }

        //return prev
        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getLength(head);
        return reverseK(head, k, len);
    }
};