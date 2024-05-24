class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp(26);
        for(char c : s) mpp[c]++;

        priority_queue<pair<int, char>> pendingNodes;
        for(auto [c, freq] : mpp){
            pendingNodes.push({freq, c});
        }

        string ans;
        while(!pendingNodes.empty()){
            auto curr = pendingNodes.top();
            pendingNodes.pop();
            ans += string(curr.first, curr.second);
        }

        return ans;
    }
};