class Solution {
private:
    bool isPossible(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)(nums[i])/(double)(mid));
        }

        return sum <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(isPossible(nums, threshold, mid)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return ans;
    }
};