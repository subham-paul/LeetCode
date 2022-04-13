class Solution {
    public boolean checkStraightLine(int[][] c) {
        if (c[0][0] == c[1][0]) {
            for (int i = 2; i < c.length; i++) {
                if (c[i][0] != c[0][0])
                    return false;
            }
            return true;
        }
        double slope = (c[0][1] - c[1][1]) / (double) (c[0][0] - c[1][0]);
        for (int i = 2; i < c.length; i++) {
            if (c[i][0] == c[0][0])
                return false;
            double cSlope = (c[0][1] - c[i][1]) / (double) (c[0][0] - c[i][0]);
            if (slope != cSlope)
                return false;
        }
        return true;
    }
}