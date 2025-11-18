class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i=0;
        while(i<n-1)
        {
            if(bits[i]==1)
            {
                if(i+1>=n-1)
                {

                return false;
                }
                else
                {
                    i=i+2;
                }
            }
            else
            {
                i++;
            }
        }
        return true;
    }
};