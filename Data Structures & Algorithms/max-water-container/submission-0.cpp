class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0;
        int currarea=0;

        int i=0;
        int n=heights.size();
        int j=n-1;
        while(i<j){
             int  currarea=min(heights[i],heights[j])*(j-i);
             area=max(area,currarea);

            if(heights[i]<heights[j]){
                i++;
            }
            else
            j--;

        } 
        return area;
    }
};
