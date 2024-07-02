class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size());
        int maxi = -1;
        for(int i=arr.size()-1;i>=0;i--){
            ans[i] = maxi;
            maxi = max(maxi, arr[i]);
            
        }

        return ans;
    }
};