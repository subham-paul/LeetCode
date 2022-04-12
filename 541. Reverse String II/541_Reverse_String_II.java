class Solution {
    public String reverseStr(String s, int k) {

        char c[] = s.toCharArray();
        for (int i = 0; i < s.length(); i = i + 2 * k) {
            int left = i, right = Math.min(s.length() - 1, i + k - 1);
            while (left < right) {
                char temp = c[left];
                c[left] = c[right];
                c[right] = temp;
                left++;
                right--;
            }
        }
        return String.copyValueOf(c);
    }
}