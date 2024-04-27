class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(auto x : nums) mpp[x]++;

        vector<vector<int>> bucket(n+1);
        for(auto x : mpp){
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;
        for(int i=n;i>=0;i--){
            if(ans.size() >= k) break;

            if(!bucket[i].empty()){
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
            }

        }

        return ans;
    }
};