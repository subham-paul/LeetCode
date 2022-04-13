class Solution {
    public char findTheDifference(String s, String t) {
        int sum = 0;
        int i = 0;
        while (i < s.length()) {
            sum += t.charAt(i) - s.charAt(i);
            i++;
        }
        sum += t.charAt(i);
        return (char) sum;
    }
}