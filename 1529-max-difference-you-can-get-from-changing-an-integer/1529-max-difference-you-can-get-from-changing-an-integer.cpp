class Solution {
public:
    int maxDiff(int num) {
        vector<int>digits;
        while(num)
        {
            int d=num%10;
            digits.push_back(d);
            num/=10;
        }
        reverse(digits.begin(), digits.end());
        vector<int>v=digits;
        int i=0;
        while(i<digits.size() && digits[i]==9)
           {
              i++;
           }
        if(i<digits.size())
        {
            int temp=digits[i];
            while(i<digits.size())
            {
                 if(digits[i]==temp)
                 {
                    digits[i]=9;
                 }
                 i++;
            }
        }
       i=0;
       if(v[i]==1)
       {
           while(i<v.size() && (v[i]==1||v[i]==0))
           {
            i++;
           }
           if(i<v.size())
           {
               int temp=v[i];
            while(i<v.size())
            {
                 if(v[i]==temp)
                 {
                    v[i]=0;
                 }
                 i++;
            }
           }
       }
       else
       {
          int temp=v[0];
          v[0]=1;
          for(int i=1;i<v.size();i++)
          {
               if(v[i]==temp)
               {
                v[i]=1;
               }
          }  
       }
       int num1=0, num2=0;
    int j=0,k=0;
    while(j<digits.size())
    {
       num1=num1*10 + digits[j];
       j++;
    }
    while(k<v.size())
    {
       num2=num2*10 + v[k];
       k++;
    }
    return num1-num2;    
    }
};