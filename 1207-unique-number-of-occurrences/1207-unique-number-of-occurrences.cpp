class Solution
{
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            unordered_map<int, int> m1, m2;
            for (int i = 0; i < arr.size(); i++)
            {
                m1[arr[i]]++;
            }
            for (auto i: m1)
            {
                m2[i.second]++;
                if (m2[i.second] > 1)
                {
                    return false;
                }
            }
            return true;
        }
};