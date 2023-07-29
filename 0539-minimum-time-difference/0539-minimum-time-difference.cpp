class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for(int i=0;i<timePoints.size();i++){
            string curr = timePoints[i];
            int hours = stoi(curr.substr(0, 2));
            int minute = stoi(curr.substr(3, 2));
            int totalMinutes = hours*60 + minute;
            minutes.push_back(totalMinutes);
        }

        sort(minutes.begin(), minutes.end());


        int minDiff = INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            int diff = minutes[i+1] - minutes[i];
            minDiff = min(minDiff, diff);
        }

        int lastDiff = (minutes[0] + 1440) - minutes[minutes.size()-1];
        minDiff = min(minDiff, lastDiff);

        return minDiff;


    }
};