class Solution {
public:
int get_ans1(string s){
    int ans=0;
    unordered_map<string,int>mp;
    mp["0+0"]=-1;
    int ac=0,bc=0,cc=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a') ac++;
        if(s[i]=='b') bc++;
        if(s[i]=='c') cc++;
        int fs=ac-bc;
        int ss=ac-cc;
        string t=to_string(fs)+"+"+to_string(ss);
        if(mp.find(t)==mp.end()){
            mp[t]=i;
        }
        else{
            ans=max(ans,i-mp[t]);
        }
    }
    return ans;
}
int get_ans(string s,char a,char b,char c){
    int ans=0;
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==a) sum++;
        if(s[i]==b) sum--;
        if(s[i]==c) {
            mp.clear();
            sum=0;
            mp[0]=i;
        }
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
        else{
            ans=max(ans,i-mp[sum]);
        }
    }
    return ans;
}
    int longestBalanced(string s) {
        int ans=0;
        ans=max(ans,get_ans(s,'a','b','c'));
        ans=max(ans,get_ans(s,'a','c','b'));
        ans=max(ans,get_ans(s,'c','b','a'));
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='a') temp=0;
            else temp++;
            ans=max(ans,temp);
        }
        temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='b') temp=0;
            else temp++;
            ans=max(ans,temp);
        }
        temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='c') temp=0;
            else temp++;
            ans=max(ans,temp);
        }
        ans=max(ans,get_ans1(s));
        return ans;
    }
};