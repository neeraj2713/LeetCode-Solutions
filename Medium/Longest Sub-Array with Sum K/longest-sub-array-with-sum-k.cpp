//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
         unordered_map<int, int> mp;
        int prefixSum = 0, maxLength = 0;
        
        for (int i = 0; i < N; ++i) {
            prefixSum += A[i];
            
            if (prefixSum == K) {
                maxLength = i + 1;
            }
            
            if (mp.find(prefixSum - K) != mp.end()) {
                maxLength = max(maxLength, i - mp[prefixSum - K]);
            }
            
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends