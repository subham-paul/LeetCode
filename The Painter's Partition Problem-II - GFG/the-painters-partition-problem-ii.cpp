//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossibleSolution(int A[], int N, int M, long long mid){
        long long timeSum = 0;
        int c = 1;
        for(int i = 0; i<N; i++){
            if(A[i] > mid){
                return false;
            }
            if(timeSum + A[i] > mid){
                c++;
                timeSum = A[i];
                if(c > M){
                    return false;
                }
            } else {
                timeSum += A[i];
                }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long start = 0, end = 0, ans = -1;
        for(int i = 0; i<n; i++){
            end += arr[i];
        }
        
        while(start <= end) {
            long long mid = start + (end- start)/2;
            if(isPossibleSolution(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends