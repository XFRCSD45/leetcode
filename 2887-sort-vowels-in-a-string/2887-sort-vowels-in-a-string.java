class Solution {
    public static boolean isVowel(Character c)
    {
        return c == 'a' || c == 'e' || c == 'o'|| c == 'u'|| c == 'i'
                || c == 'A' || c == 'E' || c == 'O'|| c == 'U'|| c == 'I';
    }
    public String sortVowels(String s) {
        int[] count = new int[200];
        int n = s.length();
        for(char c : s.toCharArray())
        {
            if(isVowel(c))
            {
                count[c-'A']++;
            }
        }
        String vwls = "AEIOUaeiou";
        StringBuilder ans = new StringBuilder();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(!isVowel(s.charAt(i)))
            {
                ans.append(s.charAt(i));
            }
            else
            {
                while(count[vwls.charAt(j)-'A'] ==0)
                {
                    j++;
                }
                ans.append(vwls.charAt(j));
                count[vwls.charAt(j)-'A']--;
            }
        }
        return ans.toString();
    }
}