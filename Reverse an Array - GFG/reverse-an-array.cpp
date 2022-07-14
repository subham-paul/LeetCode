// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, arr[100]; cin>>t;
	while(t--){
	    int n; cin>> n;
	   // taking input
	    for(int i = 0; i<n; i++){
	        cin>>arr[i];
	    }
	   // reverse
	   for(int i =0,j=n-1; i<n/2; i++, j--){
	       //int temp = arr[i];
	       //arr[i] = arr[j];
	       //arr[j] = temp;
	       swap(arr[i], arr[j]);
	   }
	   //output
	   for(int i = 0; i<n; i++){
	       cout<<arr[i] << " ";
	   } cout << endl;
	}
	return 0;
}