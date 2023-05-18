//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        
        // step 1: Push all persons into stack
        for(int i = 0; i < n; ++i){
            st.push(i);
        }
        
        // step 2: run discard method, to get a might be Celebrity
        while(st.size() != 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(M[a][b]){ // if a knows b
                // a is not a celebrity, b might be
                st.push(b);
            } else {
                st.push(a); // b is not celebrity, a might be
            }
        }
        
        // Step 3: Check that single person is actually celebrity
        int mightBeCelebrity = st.top(); st.pop();
        
        // Celebrity should not know anyone
        for(int i=0;i<n;i++){
            if(M[mightBeCelebrity][i] != 0){
                return -1;
            }
        }
        
        // Everyone should know Celebrity
        for(int i = 0; i < n; ++i){
            if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity){
                return -1;
            }
        }
        
        // mightBeCelebrity is the Celebrity
        return mightBeCelebrity;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends