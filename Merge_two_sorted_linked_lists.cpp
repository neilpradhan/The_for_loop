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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
 // Recurrsion 
    ListNode* temp = NULL ;
    
    if (!l1){return l2;}
    if (!l2){return l1;}    
        
    if (l1->val <= l2->val){
        temp = l1;
        temp->next = mergeTwoLists(l1->next,l2);
    }else{
        temp = l2;
        temp->next = mergeTwoLists(l1,l2->next);
    }

    return temp;
        
        
 // Iterative approach with new linked list
        
        if (!l1 && l2) return l2;
        if (!l2 && l1) return l1;
        if (!l2 && !l1) return NULL;
        
        
        ListNode* head = new ListNode;
        ListNode* curr = head;
        
        while(l1 != NULL && l2!=NULL)
        {
            if (l1->val<l2->val)
            {
                curr->val = l1->val;
                l1 = l1->next;

                curr->next = new ListNode;
                curr = curr->next;
                
            }
            else if(l1->val>l2->val)
            {
                curr->val = l2->val;
                l2 = l2->next;
                curr->next = new ListNode;
                curr = curr->next;
            }
            
            else
            {
                curr->val = l1->val;
                curr->next = new ListNode;
                curr = curr->next;
                curr->val = l2->val;
                l1 = l1->next;
                l2 = l2->next;
                curr->next = new ListNode;
                curr = curr->next;   
            }

        }
        
        
        while(l1 != NULL)
        {

            curr->val = l1->val;            
            curr->next = new ListNode;
            curr = curr->next;
            l1 = l1->next;

        }
 
        while(l2 != NULL)
        {

            curr->val = l2->val;
            curr->next = new ListNode;
            curr = curr->next;
            l2 = l2->next;
        } 
        
        ListNode* pt = head;
        while(pt->next->next!=NULL)
        {
            pt = pt->next;
        }
        pt->next = NULL;
        
        return head;
        
        
        
        
 // Inplace Iterative approach: no new list 
        
        
        
        if (! l1 && l2) return l2;
        if (! l2 && l1) return l1;
        if (! l2 && ! l1) return NULL;

        ListNode* head  = NULL;
        ListNode* temp  = NULL;
        

        
        while(l1 != NULL && l2 !=NULL)
        {
            if (l1->val<=l2->val)
            {
                if (head==NULL) head = l1;

                while(l1->next!=NULL && (l1->next->val <= l2->val)) l1 = l1->next;

                temp = l1->next;
                l1->next = l2;
                l1 = temp;
                
                
            }
            else 
            {
                if (head==NULL) head = l2;
                while(l2->next!=NULL && (l2->next->val <= l1->val)) l2 = l2->next;
                temp = l2->next;
                l2->next = l1;
                l2 = temp;
            }
            


        }
        
        
        return head;
        
        
        
        
        
        
        
    }
};
