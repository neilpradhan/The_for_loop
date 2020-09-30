/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

// solution 1: O(N) space complexity 


    Node* copyRandomList(Node* head) {
        
        Node* original_head = head;
        Node* l1 = head;
        
        
        if (!l1) return NULL;
        Node* l2 = new Node(l1->val);
        Node* head_2 = l2;
        
        
        
        unordered_map<Node*, Node*>  um;
        // old : new     
        
        um[l1] = l2;
        
        while(l1->next !=NULL)
        {
            l1 = l1->next;
            
            l2->next = new Node(l1->val);
            
            l2 = l2->next;
            um[l1]  = l2;
        }
        
        

        
        Node* c1 = head;
        Node* c2 = head_2;
        
        
        

        while(c1 !=NULL)
        {
            um[c1]->random = um[c1->random];
            c1 = c1->next;
        }

        
        

        
        

        
        return head_2;
        
        
    }
    
 // solution 2: O(1) space complexity 
 
    Node* copyRandomList(Node* head) {
        
        Node* original_head = head;
        Node* l1 = head;

        if (!head)  return NULL;
        
        Node* k = l1;       
        
        while(k!=NULL)
        {
        // cout<<k->val<<" ";
        Node* l2 = new Node(k->val);
        l2->next = k->next;
            
        k->next = l2;
        k = k->next->next;
        }
        
        
        k = l1;
        
        while( k!=NULL )
        {
            if (k->random !=NULL)
            {
                k->next->random  = k->random->next;                
            }

            k = k->next->next;
        }
        
        
        Node* og = head; // original 
        Node* cl  = head->next; // cloned
        Node* final_ans = cl; 
        
        
        while(cl !=NULL && og !=NULL )
        {
            og->next = og->next ? og->next->next: og->next;
            cl->next = cl->next? cl->next->next: cl->next;
            og = og->next;
            cl = cl->next;

        }
        
        
        
        
        k = l1;
        
         return final_ans;   
        

        
    }
};
