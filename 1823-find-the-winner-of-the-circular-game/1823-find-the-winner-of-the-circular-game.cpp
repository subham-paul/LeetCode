class Solution
{
    public:
        int solve(int n, int k)
        {
           	///base case
            if (n == 1)
                return 0;

           	//curr answer is dependant on the previous answer with a difference of k 
            return (solve(n - 1, k) + k) % n;
        }

    int findTheWinner(int n, int k)
    {
       	//adding 1 to make 1 based indexing as we used mod operator
        int ans = solve(n, k) + 1;
        return ans;
    }
};