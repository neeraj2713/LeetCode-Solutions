class Solution {
public:
    bool isValid(string& s, string& target){
        int changedCount = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != target[i]) changedCount++;
        }
        if(changedCount == 1) return true;
        return false;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        bank.push_back(startGene);
        int n = bank.size();
        vector<bool> visited(n, false);
        visited[n-1] = true;
        queue<string> q;
        q.push(startGene);
        int stepCounts = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();
                if(curr == endGene) return stepCounts;
                for(int i=0;i<n;i++){
                    bool valid = isValid(curr, bank[i]);
                    if(!valid || visited[i]) continue;
                    visited[i] = true;
                    q.push(bank[i]);
                }
            }
            stepCounts++;
        }

        return -1;
    }
};