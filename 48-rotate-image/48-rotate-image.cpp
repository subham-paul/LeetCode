class Solution
{
    public:
        void rotate(vector<vector < int>> &matrix)
        {
            vector<vector < int>> grid = matrix;
            int n = grid.size();
            int m = grid[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[j][n - 1 - i] = grid[i][j];	//if u will observe u can see matrix following the pattern[j][n-1-i]=[i][j]
                }
            }
        }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate Image.
// Memory Usage: 7.3 MB, less than 33.50% of C++ online submissions for Rotate Image.