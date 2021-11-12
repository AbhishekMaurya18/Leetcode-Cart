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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }
        while(head && head->val==val){
            head=head->next;
        }
        
        ListNode *cur=head,*pre=head;
        
        while(cur){
            while(cur && cur->val==val){
                pre->next=cur->next;
                cur=cur->next;
            }
            pre=cur;
            if(cur)
                cur=cur->next;
        }
        
        return head;
        
    }
};