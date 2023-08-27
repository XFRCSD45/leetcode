class Solution {
public:
    bool solve(vector<int>& stones, int ind, int k, unordered_map<int, int>& map, unordered_map<int, unordered_map<int, bool>>& mp) {
        if (ind == stones.size() - 1)
            return true;
        
        if (mp.find(ind) != mp.end() && mp[ind].find(k) != mp[ind].end()) {
            return mp[ind][k];
        }
        
        bool ans1 = false, ans2 = false, ans3 = false;
        if (map.find(stones[ind] + k) != map.end()) {
            int curr = map[stones[ind] + k];
            if (curr > ind)
                ans1 = solve(stones, curr, k, map, mp);
        }
        if (k > 1 && map.find(stones[ind] + k - 1) != map.end()) {
            int curr = map[stones[ind] + k - 1];
            if (curr > ind)
                ans2 = solve(stones, curr, k - 1, map, mp);
        }
        if (map.find(stones[ind] + k + 1) != map.end()) {
            int curr = map[stones[ind] + k + 1];
            if (curr > ind)
                ans3 = solve(stones, curr, k + 1, map, mp);
        }
        
        return mp[ind][k] = ans1 || ans2 || ans3;
    }
    
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> map;
        for (int i = 0; i < stones.size(); i++) {
            map[stones[i]] = i;
        }
        
        if (stones.size() == 2) {
            if (stones[1] == 1)
                return true;
            else
                return false;
        }
        if(stones[1]!=1)
            return false;
        
        int ind = 1;
        int k = 1;
        unordered_map<int, unordered_map<int, bool>> mp;
        return solve(stones, ind, k, map, mp);
    }
};
