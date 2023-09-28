//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        int spaces = 2*n-2;
        
        for(int i = 1;i<=2*n-1;i++){  // Outer loop for printing row.
          
          int stars = i; // stars for first half
          
          if(i>n) stars = 2*n - i; // stars for the second half.
          
          for(int j=1;j<=stars;j++){ //for printing the stars
              cout<<"*";
          }
          
          for(int j = 1;j<=spaces;j++){ //for printing the spaces
              cout<<" ";
          }
          
          for(int j = 1;j<=stars;j++){  //for printing the stars
              cout<<"*";
          }
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
          if(i<n) spaces -=2;
          else spaces +=2;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends