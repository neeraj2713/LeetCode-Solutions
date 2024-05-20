class Solution {
private:
    bool countHours(vector<int>& piles, int mid, int h){
        long long totalHours = 0;
        for(int i=0;i<piles.size();i++){
            totalHours += (ceil((double)piles[i]/(double)mid));
        }
        return totalHours <= h ? true : false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());

        while(s<=e){
            int mid = s+(e-s)/2;
            if(countHours(piles, mid, h)){
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};