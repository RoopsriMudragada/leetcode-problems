class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int w = sqrt(area); w >= 1; w--){
            if(area % w == 0){
                int l = area / w;

                return {l, w};
            }
        }
        return {};
    }
};