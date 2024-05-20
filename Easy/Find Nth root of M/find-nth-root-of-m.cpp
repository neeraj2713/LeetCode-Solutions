//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int helper(int mid, int n, int m){
	    long long ans = 1;
	    for(int i=1;i<=n;i++){
	        ans = ans*mid;
	        if(ans > m) return 2;
	    }
	    if(ans == m) return 1;
	    return 0;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int s = 1;
	    int e = m;
	    
	    while(s<=e){
	        int mid = s+(e-s)/2;
	        int value = helper(mid, n, m);
	        if( value == 1){
	            return mid;
	        } else if(value == 2) {
	            e = mid-1;
	        } else {
	            s = mid+1;
	        }
	        
	    }
	    
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends