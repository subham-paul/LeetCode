class Solution {
    public int removeElement(int[] A, int val) {
        int m = 0;
        for (int i = 0; i < A.length; i++) {

            if (A[i] != val) {
                A[m] = A[i];
                m++;
            }

        }
        return m;
    }
}