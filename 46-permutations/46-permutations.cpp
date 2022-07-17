class Solution
{
    private:
        void solve(vector<int> nums, vector<vector< int>> &ans, int index)
        {
           	// base case
            if (index >= nums.size())
            {
                ans.push_back(nums);
                return;
            }
            for (int loop = index; loop < nums.size(); loop++)
            {
                swap(nums[index], nums[loop]);
                solve(nums, ans, index + 1);
               	// BackTracking
                swap(nums[index], nums[loop]);
            }
        }
    public:
        vector<vector < int>> permute(vector<int> &nums)
        {
            vector<vector < int>> ans;
            int index = 0;
            solve(nums, ans, index);
            return ans;
        }
};