class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& v) {
        sort(v.begin(), v.end());
        long long int curr =mass;
        for(int i=0;i<v.size();i++)
        {
            if(curr < v[i])
            {
                return false;
            }
            curr+=v[i];
        }
        return true;
    }
};