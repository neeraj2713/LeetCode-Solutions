class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;
        long long ans = 0;

        while(s<=e){
            long long mid = s+(e-s)/2;
            long long square = mid*mid;
            if(square == x){
                return mid;
            } else if(square > x){
                e = mid-1;
            } else {
                ans = mid;
                s = mid+1;
            }
        }

        return ans;
    }
};