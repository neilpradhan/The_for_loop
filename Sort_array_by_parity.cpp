class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& A) {
        int even  = 0;
        int odd = A.size()-1;
        
        auto even_lambda = [](const auto& a )
        {
            return (a%2 == 0) ? 1: 0; 
        };
        
        auto swap_lambda = [](auto & a, auto & b)
        {
            { auto c = a;a = b;b = c;};
        };
        
        while(even<odd)
        {
            if  ( (!even_lambda(A[even])) && (even_lambda(A[odd])) )
            {
                swap_lambda(A[even],A[odd]);
            }
            
            if (even_lambda(A[even]))
                {
                    even++;
                }
                
            if (!even_lambda(A[odd]))
                {
                    odd--;
                }    
                
                
        }
        return A;        
                
                
        
        
        
    }
};
