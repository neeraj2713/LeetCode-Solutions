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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> list;
        ListNode* curr = head;
        while(curr){
            list.push_back(curr->val);
            curr = curr->next;
        }

        swap(list[k-1], list[list.size()-k]);
        ListNode* temp = new ListNode(list[0]);
        ListNode* head1 = temp;

        for(int i=1;i<list.size();i++){
            temp->next = new ListNode(list[i]);
            temp = temp->next;
        }
        return head1;
        
    }
};