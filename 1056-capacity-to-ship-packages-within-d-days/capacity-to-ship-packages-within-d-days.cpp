class Solution {
private:
    bool isPossible(vector<int>& weights, int days, int mid) {
        int count = 1;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] > mid) return false;
            if(sum + weights[i] > mid) {
                count++;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }

        return count <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = 1;
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPossible(weights, days, mid)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};