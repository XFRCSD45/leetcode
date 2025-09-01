class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())
        {
            return false;
        }

        char[] chars1 = s.toCharArray();
        char[] chars2 = t.toCharArray();

        Arrays.sort(chars1);
        Arrays.sort(chars2);

        String sortedS = new String(chars1);
        String sortedT = new String(chars2);
        return sortedS.equals(sortedT);
    }
}