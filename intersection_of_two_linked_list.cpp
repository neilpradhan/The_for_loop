/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        
        
        ListNode *curr = headA;
        ListNode *curr2 = headB;
        int l1 = 0;
        int l2 = 0;
        
        while(curr)
        {
            curr = curr->next;
            l1++;
        }
        
        while(curr2)
        {
            curr2 = curr2->next;
            l2++;
        }
        
        int diff = abs(l1-l2);
        
        
        
        
        //cout<<diff;
        ListNode *c1 = headA;
        ListNode *c2 = headB;
        
        if (l1>l2)
        {
            while(diff--)
            {
                c1 = c1->next;
            } 
            
        }
        
        else
        {
            while (diff--){
                c2 = c2->next;
            } 
        }
        
        while(c1!=c2)
        {
            c1 = c1->next;
            c2 = c2->next;
        }
        return c1;

        
    }
};
