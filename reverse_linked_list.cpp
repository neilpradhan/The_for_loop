// LEETCODE
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
  
ListNode* helper(ListNode* head)
{   
    // 1->2->3->4
    
    if (head->next == NULL)
    {   
        return head;
    }
    
    
    
    ListNode* temp = head->next;
    
    head->next = NULL;
    
    ListNode* part_ans = helper(temp);
    
    temp->next = head;
    
    return part_ans;
    
}
    
     
    
     
    
    
    
    ListNode* reverseList(ListNode* head)
    {
        if (!head) return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
            
        
        // return helper(curr);
        
        
        while(curr!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
        }
        
        return prev;
        

        
        
    }
    

    
    
    
    
    
    
    
    
    
    
};
