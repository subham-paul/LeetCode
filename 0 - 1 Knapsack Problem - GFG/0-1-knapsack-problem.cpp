//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int capacity, int weight[], int value[], int n) 
    { 
       // Your code here
       vector<int> curr(capacity + 1, 0);

        for (int w = weight[0]; w <= capacity; w++) {
            if (weight[0] <= capacity) {
                curr[w] = value[0];
            }
            else
                curr[w] = 0;
        }
    
        for (int index = 1; index < n; index++) {
            for (int wt = capacity; wt >= 0; wt--) {
                // include and exclude
                int include = 0;
                if (weight[index] <= wt)
                    include = value[index] + curr[wt - weight[index]];
    
                int exclude = 0 + curr[wt];
    
                curr[wt] = max(include, exclude);
            }
        }
        return curr[capacity];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends