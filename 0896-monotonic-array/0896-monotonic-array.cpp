class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        if(arr.size()==1)
            return true;
        int n=arr.size();
        int i=0;
        while(i<n-1 && arr[i]==arr[i+1])
        {
                  i++;
        }
        if(i<n-1 && arr[i]<arr[i+1])
        {
                 for(;i<arr.size()-1;i++)
                 {
                        if(arr[i]>arr[i+1])
                            return false;
                 }
           
        }
        else
        {
                    for(;i<arr.size()-1;i++)
                 {
                        if(arr[i]<arr[i+1])
                            return false;
                 }
            
        }
        return true;
    }
};