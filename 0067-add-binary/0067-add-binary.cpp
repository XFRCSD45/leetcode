class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 && j>=0)
        {
            int sum = (a[i]-'0')+ (b[j]-'0') + carry;
            int rem = sum%2;
            carry =sum/2;
            ans+=rem+'0';
            i--;
            j--;
        }
        while(i>=0)
        {
            int sum = (a[i]-'0')+ carry;
            int rem = sum%2;
            carry =sum/2;
            ans+=(rem+'0');
            i--;
        }
        while( j>=0)
        {
            int sum = (b[j]-'0') + carry;
            int rem = sum%2;
            carry =sum/2;
            ans+=(rem+'0');
            j--;
        } 
        if(carry)
        {
            ans+=(carry+'0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};