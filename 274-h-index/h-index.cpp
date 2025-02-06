class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n+1, 0);

        for(int i=0;i<n;i++){
            if(citations[i] > n){
                bucket[n]++;
            } else {
                bucket[citations[i]]++;
            }
        }

        int count = 0;
        for(int i=bucket.size()-1;i>=0;i--){
            count += bucket[i];
            if(count >= i) return i;
        }

        return -1;
    }
};