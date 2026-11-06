class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        if(n==0) return 0;

        sort(boxTypes.begin(),boxTypes.end(),[](const auto &a, const auto &b){
            return a[1] > b[1];
        });

        double units = 0;

        for(int i = 0; i < n; i++){

            int boxesToTake = min(truckSize,boxTypes[i][0]);
            units += boxesToTake * boxTypes[i][1];
            truckSize -= boxesToTake;

            if(truckSize == 0) break;
        }
        return units;
    }
};