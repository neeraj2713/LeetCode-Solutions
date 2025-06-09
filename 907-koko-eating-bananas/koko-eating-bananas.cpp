class Solution {
private:
    bool findHours(vector<int>& piles, int h, int k){
        int totalHours = 0;
        for(int i=0;i<piles.size();i++){
            totalHours += ceil((double)(piles[i]) / (double)(k));
            if(totalHours > h) return false;
        }

        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(findHours(piles, h, mid)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};