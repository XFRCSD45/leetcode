class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        for(int i=0;i<s.size();)
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }
      
            int j=i+1;
            while(j<s.size() && s[j]!=' ')
            {
                j++;
            }
            if(j!=i+1)
            {
              reverse(s.begin()+i,s.begin()+j);
              i=j+1;
            } 
            else
            {
                i++;
            }
        }
        int i=0;
        while(s[i]==' ')
        {
            s.erase(s.begin()+i);
            
        }
        for( i=0;i<s.size();)
        {   
           
            if(s[i]==' ')
            {
                int k=i+1;
                while(k<s.size() && s[k]==' ')
                {
                    s.erase(s.begin()+k);
                    
                }
                i=k;
            }
            else
            {
                i++;
            }
        }
        int k=s.size()-1;
        while(s[k]==' ')
        {
          s.erase(s.begin()+k);
          k--;  
        }
        return s;
    }
};