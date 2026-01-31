class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        int n=letters.size();
        for(int i=0;i<n;i++)
        {
            if(letters[i]>target)
            {
                ans=letters[i];
                return ans;
            }
        }
        return ans;
    }
};