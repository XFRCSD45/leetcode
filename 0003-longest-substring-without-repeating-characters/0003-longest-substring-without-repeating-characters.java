class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> lastOcc = new HashMap<>();

        int start = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (lastOcc.containsKey(ch) && lastOcc.get(ch) >= start) {
                start = lastOcc.get(ch) + 1;
            }

            lastOcc.put(ch, i);
            ans = Math.max(ans, i - start + 1);
        }

        return ans;
    }
}
