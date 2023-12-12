//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int x = 0;
        for(int i=0;i<n;i++){
            x ^= arr[i];
            x ^= (i+1);
        }
        
        int setBit = x&(~(x-1));
        vector<int> ans(2, 0);
        
        for(int i=0;i<n;i++){
            if(arr[i]&setBit){
                ans[0] ^= arr[i];
            } else {
                ans[1] ^= arr[i];
            }
            
            if((i+1)&setBit){
                ans[0] ^= (i+1);
            } else {
                ans[1] ^= (i+1);
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i] == ans[0]) break;
            if(arr[i] == ans[1]){
                swap(ans[0], ans[1]);
                break;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends