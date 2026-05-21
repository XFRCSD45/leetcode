class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        vector<pair<string,int>>ans;
        for(int i=0;i<n;i++){
            ans.push_back({to_string(arr1[i]),1});
        }
        for(int i=0;i<m;i++){
            ans.push_back({to_string(arr2[i]),2});
        }
        sort(ans.begin(),ans.end());
        int maxi=0;
        int j=m+n-1;
        while(j>=1){
            string s1=ans[j].first;
            int b1=ans[j].second;
            string s2=ans[j-1].first;
            int b2=ans[j-1].second;
            if(b1==b2){
                j--;
            }
            else{
            int x=s1.size();
            int y=s2.size();
            int k=0;
            int c=0;
            while(k<x && k<y && s1[k]==s2[k]){
                c++;
                k++;
            }
            maxi=max(c,maxi);
            
            j--;
            }
        }
        return maxi;


    }
};