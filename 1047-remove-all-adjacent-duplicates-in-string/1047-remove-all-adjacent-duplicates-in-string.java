class Solution {

    public String removeDuplicates(String s) {
        char[] ch = new char[s.length()];
        int i = 0;
        for (int loop = 0, length = s.length(); loop < length; loop++) {
            if (i > 0 && ch[i - 1] == s.charAt(loop)) {
                i--;
            } else {
                ch[i] = s.charAt(loop);
                i++;
            }
        }
        return new String(ch, 0, i);
    }
}
