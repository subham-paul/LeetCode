class Solution {

    public boolean isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        long z = 3;
        while ((int) z <= n) {
            if (z == n) {
                return true;
            } else {
                z *= 3;
                if (z > Integer.MAX_VALUE) {
                    break;
                }
            }
        }
        return false;
    }
}
