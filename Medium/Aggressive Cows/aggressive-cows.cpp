//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool possible(int n, int k, vector<int> stalls, int mid){
        int cowCount = 1;
        int last = stalls[0];
        
        for(int i=1;i<n;i++){
            if(stalls[i]-last >= mid){
                cowCount++;
                last = stalls[i];
            }
            
            if(cowCount >= k) return true;
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int s = 1;
        int e = stalls[n-1]-stalls[0];
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(possible(n, k, stalls, mid) == true){
                ans = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends