/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    

    
   // recurrsive 
   int  helper_recursive(TreeNode* root, int k)
    {
        if (!root) return 0;
       
       
        //k = (k<<1) | root->val;
        k = 2* k + root->val;
       
        if (!root->left && !root->right)
        {
            return k;
        }
        
       
        
        return helper_recursive(root->left,k) + helper_recursive(root->right, k);
    }
    
    
    // iterative
    int helper_iterative(TreeNode* root)
    {
        if (!root) return 0;
        stack<pair<TreeNode*,int>> s;
        s.push({root,0});
        
        int sum = 0;
        while(!s.empty())
        {
            
            auto curp = s.top();
            s.pop();
            TreeNode* curr = curp.first;
            int k = curp.second;
            
            k = k* 2 + curr->val;
            
            if (!curr->left && !curr->right)
                sum  += k;
            
            
            if (curr->left) s.push({curr->left,k});
            if (curr->right) s.push({curr->right,k});
        }
        
        return sum;
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        TreeNode* curr = root;
         return helper_recursive(curr,0);
        //return helper_iterative(root);
        
    }
    

    


};
