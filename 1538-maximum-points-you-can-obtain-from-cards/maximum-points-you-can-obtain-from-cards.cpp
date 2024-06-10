class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ls=0;
        int rs=0;
        int ri=n-1;
        int maxi=0;
        for(int i=0;i<k;i++)
        {
            ls+=cardPoints[i];
        }
        maxi=ls;
        for(int i=k-1;i>=0;i--)
        {
            ls-=cardPoints[i];
            rs+=cardPoints[ri];
            ri--;
            maxi=max(maxi,ls+rs);
        }
        return maxi;
    }
};