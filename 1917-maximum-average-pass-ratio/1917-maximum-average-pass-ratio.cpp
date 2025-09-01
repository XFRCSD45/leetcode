class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        priority_queue<pair<double,int>> pq;
        int n = classes.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int total = classes[i][1];
            int pass = classes[i][0];
            if(total == pass)
            {
                continue;
            }
            double avg = pass*1.0/total;
            pass++;
            total++;
            double nexAvg = pass*1.0/total;
            double change = nexAvg - avg;
            pq.push({change,i});
        }
        for(int i=1;i<=extra && !pq.empty();i++)
        {
            pair<double,int> p = pq.top();
            pq.pop();
            if(p.first ==0.0)
            {
                break;
            }
            classes[p.second][0]+=1;
            classes[p.second][1]+=1;
            int total = classes[p.second][1];
            int pass = classes[p.second][0];
            double avg = pass*1.0/total;
            pass++;
            total++;
            double nexAvg = pass*1.0/total;
            double change = nexAvg - avg;
            pq.push({change,p.second});
            // cout<<p.second<<" ";
        }
        double sum =0.0;
        for(int i=0;i<n;i++)
        {
            int total = classes[i][1];
            int pass = classes[i][0];
            double avg = pass*1.0/total;
            sum+=avg;
        }
        double average = sum/n;
        average = round(average * 1e5) / 1e5;
        return average;
    }
    
};