class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int sum_all = accumulate(arr.begin(), arr.end(), 0);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = arr[i];
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++)
            {
                sum += arr[j];
                count++;
                if (count % 2 != 0)
                {
                    ans += sum;
                }
            }
        }
        ans += sum_all;
        return ans;
    }
};