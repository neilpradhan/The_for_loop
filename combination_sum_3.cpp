class Solution {
public:
    
    
    
    
    vector<vector<int>> ans;
    
    void func(vector<int> possible, int c,int k,int sum_l)
    {
        
        possible.push_back(c);
        if (k==0 && sum_l==0)
        {
            ans.push_back(possible);
            
            return;
        }
        
        if (k<=0 || sum_l<0)
        {
            possible.pop_back(); 
            return;
        }
        
        
       

        
        for(int i=c+1;i<=9;i++)
        {
            func(possible,i,k-1,sum_l-i);
        }
        
               
        
            
        
    }
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> poss;
        
        for(int i=1;i<=9;i++)
        {
            func(poss,i, k-1,n-i);
        }
        
            
     
        
        return ans;
        
        
    }
};
