class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int bi = 0, pi = 0, capFilled = 0;
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        while(bi < buses.size()){
            capFilled = 0;
            while(capFilled < capacity && pi < passengers.size() && passengers[pi] <= buses[bi]){
                capFilled++;
                pi++;
            }
            bi++;
        }

        pi--;
        if(capFilled < capacity && (pi<0 || buses[buses.size()-1] != passengers[pi])){
            return buses[buses.size()-1];
        }

        while(pi>0 && (passengers[pi]-1 )== passengers[pi-1]){
            pi--;
        }

        return passengers[pi]-1;
    }
};