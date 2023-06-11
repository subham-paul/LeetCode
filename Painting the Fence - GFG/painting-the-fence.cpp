//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long mod = 1000000007;
    long long countWays(int n, int k){
        if(n==1) return k;
        // SPACE OPTIMIZATION
        long long prev2 = k;
        long long prev1 = (k + k * (k - 1));
    
        for (int i = 3; i <= n; i++) {
    
            long long curr = ((prev2 + prev1) * (k - 1)) % mod;
    
            // shhift -> yaha hi galti karunga ya karungi
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends