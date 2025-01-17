//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool allocatePages(vector<int>& arr, int k, int mid){
        int pages = 0;
        int count = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > mid) return false;
            if(pages + arr[i] > mid){
                count++;
                pages = arr[i];
            } else {
                pages += arr[i];
            }
        }
        
        return count <= k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        int s = 0;
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(allocatePages(arr, k, mid)){
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

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends