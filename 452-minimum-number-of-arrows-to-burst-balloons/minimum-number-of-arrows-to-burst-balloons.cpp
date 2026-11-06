class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(),points.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int count = 1;
        int lastPoint = points[0][1];

        for(int i = 0; i < n; i++){
            if(lastPoint < points[i][0]){
                count++;
                lastPoint = points[i][1];
            }
        }
        return count;
    }
};