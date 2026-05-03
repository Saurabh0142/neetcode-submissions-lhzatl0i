class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;

        int area=0;
        while(i<j){
            int mini=min(heights[i],heights[j]);
            int dis=j-i;
            area=max(area,mini*dis);
            
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};
