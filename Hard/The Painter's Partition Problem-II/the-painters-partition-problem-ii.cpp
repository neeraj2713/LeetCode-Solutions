//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int arr[], int n, int k, long long mid){
        int count = 1;
        long long lengthSum = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] > mid) return false;
            if(lengthSum + arr[i] > mid){
                count++;
                lengthSum = arr[i];
                if(count > k) return false;
            } else {
                lengthSum += arr[i];
            }
        }
        
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        long long s = 0;
        long long e = 0;
        for(int i=0;i<n;i++){
            e += arr[i];
        }
        long long ans = -1;
        
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(isPossible(arr, n, k, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
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