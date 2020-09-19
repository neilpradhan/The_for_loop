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
    
    ListNode* mover = NULL;
    ListNode* t=NULL;
    
    // recurrsive approach
    bool func_recursive(ListNode* mover)
    {
        if (!mover) return true;
        
        bool part_ans = func_recursive(mover->next) && (mover->val == t->val);
        
        t = t->next;
        
        
        return part_ans;
        
        
           
    }
    
    // iterative approach
    bool func_iterative(ListNode* mover)
    {
        stack<ListNode*> s;
        
        while(mover !=NULL)
        {
            s.push(mover);
            mover = mover->next;
        }
        
        bool ans = true;
        
        while(!s.empty() && t)
        {
        auto f  = s.top();
        s.pop();
        ans = ans && (f->val == t->val);
        t = t->next;    
            
        }
        
        return ans;

    }
    
    
    bool isPalindrome(ListNode* head) {
        mover = head;
        t = head;
        return func_iterative(mover);
    }
    
    
};





