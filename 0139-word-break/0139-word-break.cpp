class Solution {
public:
   int solve(string s, vector<string> &B, unordered_map<string,int>&m,int dic )
{
    int n=s.size();
    if(n==0)
    return 1;
    if(m[s]!=0)
    return m[s];
    for(int i=1;i<=n;i++)
    {  int f=0;
        string temp=s.substr(0,i);
        for(int j=0;j<dic;j++)
        {
            if(temp.compare(B[j])==0)
            {
                f=1;
                break;
            }
        }
        if(f==1 && solve(s.substr(i,n-i),B,m,dic)==1)
        return m[s]=1;
    }
    return m[s]=-1;
    
    
}
    bool wordBreak(string A, vector<string>& B) {
        unordered_map<string,int>m;
        int dic=B.size();
        int ans=solve(A,B,m,dic);
        
        if(ans==1)
        return 1;
        else
        return 0;
    }
};