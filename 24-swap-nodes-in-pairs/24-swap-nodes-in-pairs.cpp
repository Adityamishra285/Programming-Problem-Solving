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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode *prev, *N, *NN, *curr;
        curr = head;
        prev = NULL;
        ListNode *head2;
        
        if(head==NULL || head->next==NULL)
            return head;
        
        
        head2 = head->next;
                
        while(curr!=NULL && curr->next!=NULL){
            N = curr->next;
            NN = N->next;
            N->next = curr;
            curr->next = NN;
            if(prev!=NULL){
                prev->next = N;
            }
                prev = curr;
            
            curr = NN;
        }
        
        return head2;
    }
};