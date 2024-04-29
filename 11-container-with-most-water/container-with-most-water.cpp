class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int start = 0;
        int end = n-1;

        while(start<=end){
            int storage = min(height[start], height[end]) * (end-start);
            ans = max(ans, storage);
            if(height[start] < height[end])
                start++;
            else 
                end--;
        }
        return ans;
    }
};