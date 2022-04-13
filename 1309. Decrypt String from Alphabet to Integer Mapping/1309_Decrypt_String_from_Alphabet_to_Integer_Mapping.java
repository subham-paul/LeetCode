class Solution {
    public String freqAlphabets(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0;) {
            if (s.charAt(i) == '#') {
                sb.append((char) ('a' + Integer.valueOf(s.substring(i - 2, i)) - 1));
                i -= 3;
            } else {
                sb.append((char) ('a' + Integer.valueOf(s.substring(i, i + 1)) - 1));
                i--;
            }
        }
        return sb.reverse().toString();
    }
}