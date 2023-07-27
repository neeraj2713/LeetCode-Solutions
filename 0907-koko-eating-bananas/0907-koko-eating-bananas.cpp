class Solution {
public:
    bool countHours(vector<int>& piles, int h, int mid){
        double totalHours = 0;
        for(int i=0;i<piles.size();i++){
            totalHours += ceil((double)piles[i]/(double)mid);
        }

        return totalHours<=h?true:false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(countHours(piles, h, mid)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};