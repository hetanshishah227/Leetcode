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
            if(boxTypes[i][0] <= truckSize){
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }

            else{
                units += truckSize * boxTypes[i][1];
                break;
            }

        }
        return units;
    }
};