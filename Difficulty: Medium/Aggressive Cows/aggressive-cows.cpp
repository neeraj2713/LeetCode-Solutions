//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(vector<int>& stalls, int k, int mid){
        int cows = 1;
        int distance = stalls[0];
        for(int i=0;i<stalls.size();i++){
            if(stalls[i] - distance >= mid){
                cows++;
                if(cows == k) return true;
                distance = stalls[i];
            }
        }
        
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int e = stalls[stalls.size()-1] - stalls[0];
        int ans = -1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(stalls, k, mid)){
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends