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

        int c=0;
        int sum=0;
        ListNode *temp, *curr=NULL, *res=NULL;
        
        while(l1!=NULL || l2!=NULL){
            sum = c+(l1?l1->val:0)+(l2?l2->val:0);
            if(sum>=10){
                c = 1;
            }
            else{
                c = 0;
            }
            sum = sum%10;
            
            temp = new ListNode(sum);
            if(res==NULL)
                res = temp;
            else
                curr->next = temp;
            curr = temp;
            
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(c>0){
            temp = new ListNode(c);
            curr->next = temp;
            curr = temp;
        }
        return res;
    
    }
};