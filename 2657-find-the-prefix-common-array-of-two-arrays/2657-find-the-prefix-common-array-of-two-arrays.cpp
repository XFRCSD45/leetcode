class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int,bool>m1,m2;
        int count1=0, count2=0;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            m1[A[i]]=true;
            m2[B[i]]=true;
            if(m1[B[i]])
            {
                count2++;
            }
            if(m2[A[i]])
            {
                count1++;
            }
            if(A[i]==B[i])
            {
                count1--;
            }
            ans[i]=count1+count2;
        }
        return ans;
    }
};