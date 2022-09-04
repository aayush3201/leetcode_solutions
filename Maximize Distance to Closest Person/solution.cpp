class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int>closeR;
        vector<int>closeL;
        for(int i = 0; i<seats.size(); i++){
            closeR.push_back(0);
            closeL.push_back(0);
        }
        int dist = INT_MAX-20000;
        for(int i = 0; i<seats.size(); i++){
            if(seats[i] == 1){
                dist = 0;
                closeL[i] = 0;
            } else {
                closeL[i] = dist+1;
                dist++;
            }
        }
        dist = INT_MAX-20000;
        for(int i = seats.size()-1; i>=0; i--){
            if(seats[i] == 1){
                dist = 0;
                closeR[i] = 0;
            } else {
                closeR[i] = dist+1;
                dist++;
            }
        }
        int maxDist = 0;
        for(int i = 0; i<seats.size(); i++){
            maxDist = max(maxDist,min(closeR[i],closeL[i]));
        }
        return maxDist;
    }
};
