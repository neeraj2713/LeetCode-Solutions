class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> v;

        for(int i=0;i<dist.size();i++){
            v.push_back((float)dist[i]/speed[i]);
        }

        sort(v.begin(), v.end());
        int count = 0;
        int time = 0;
        int i = 0;

        while(i < v.size()){
            if(time >= v[i]){
                return count;
            }

            count++;
            time++;
            i++;
        }

        return count;
    }
};