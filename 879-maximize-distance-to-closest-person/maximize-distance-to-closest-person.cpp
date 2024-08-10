class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxDist = 0;
        int lastPerson = -1;
        int firstPerson = -1;

        for(int i=0;i<n;i++){
            if(seats[i] == 1){
                if(firstPerson == -1){
                    firstPerson = i;
                } else {
                    maxDist = max(maxDist, (i-lastPerson)/2);
                }
                lastPerson = i;
            }
        }

        maxDist = max(maxDist, firstPerson);
        maxDist = max(maxDist, n - 1 - lastPerson);

        return maxDist;
    }
};