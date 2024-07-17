class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //step 1 : initialize hashmap where key = position and value = gaps
        map<int, int> mpp;

        //step 2 : count rows
        int rows = wall.size();

        //step 3 : fill up hashmap
        for(int i=0;i<wall.size();i++){
            int size = 0;
            int cols = wall[i].size()-1;
            for(int j=0;j<cols;j++){
                size += wall[i][j];
                mpp[size]++;
            }
        }

        //step 4 : count max gaps in hashmap
        int max_gaps = 0;
        for(auto v : mpp){
            max_gaps = max(max_gaps, v.second);
        }

        //step 5 : return max gaps - rows
        return rows - max_gaps;
    }
};