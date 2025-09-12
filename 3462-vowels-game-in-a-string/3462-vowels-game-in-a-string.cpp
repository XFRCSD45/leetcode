class Solution {
public:
bool isVowel(char c)
{
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return true;
    }
    return false;
}
    bool doesAliceWin(string s) {
        int count =0;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }
        return count!=0;
    }
};