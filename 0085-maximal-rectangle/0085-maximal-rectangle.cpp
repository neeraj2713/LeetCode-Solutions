class Solution {
private:
    vector<int> nextSmallerElement(vector<int> heights, vector<int>& next){
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            next[i] = (st.empty())?heights.size():st.top();
            st.push(i);
        }
        
        return next;
    }
    
    vector<int> prevSmallerElement(vector<int> heights, vector<int>& prev){
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            prev[i] = (st.empty())?(-1):st.top();
            st.push(i);
        }

        return prev;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        nextSmallerElement(heights, next);
        
        vector<int> prev(n);
        prevSmallerElement(heights, prev);
        
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            int bars = next[i] - prev[i] - 1;
            int area = bars*heights[i];
            res = max(res, area);
        }
        
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int maxArea = -1;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};