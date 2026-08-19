class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        int ans=0;
        sort(reservedSeats.begin(), reservedSeats.end(), [&](const vector<int>&a, const vector<int>&b){
            if(a[0]==b[0])
            {
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        int rows=0;
        int i=0;
        while(i<m)
        {
            int currRow=reservedSeats[i][0];
            vector<int>seats;
            seats.push_back(reservedSeats[i][1]);
            int j=i+1;
            while(j<m && reservedSeats[j][0]==reservedSeats[i][0])
            {
                seats.push_back(reservedSeats[j][1]);
                j++;
            }
            int first=1, second=1, third=1;
            for(int k=0;k<seats.size();k++)
            {
                if(seats[k]>=2 && seats[k]<=5)
                {
                    first = 0;
                }
                 if(seats[k]>=4 && seats[k]<=7)
                {
                    second=0;
                }
                 if(seats[k]>=6 && seats[k]<=9)
                {
                    third=0;
                }
            }
            if(first && second && third)
            {
                ans+=2;
            }
            else if(first || second||third)
            {
                ans+=1;
            }
            i=j;
            rows++;
            // cout<<i<<" "<<ans<<endl;
        }
        // cout<<ans<<endl;
        // cout<<rows<<endl;
        ans= ans  + (n-rows)*2;
        return ans;
    }
};