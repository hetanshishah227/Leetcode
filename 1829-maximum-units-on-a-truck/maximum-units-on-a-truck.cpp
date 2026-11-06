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

            int numBoxes = boxTypes[i][0];
            int unitsPerBox = boxTypes[i][1];


            int boxesToTake = min(truckSize,numBoxes);
            units += boxesToTake * unitsPerBox;
            truckSize -= boxesToTake;

            if(truckSize == 0) break;
        }
        return units;
    }
};