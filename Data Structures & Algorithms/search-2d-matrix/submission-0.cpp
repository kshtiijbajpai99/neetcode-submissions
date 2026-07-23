class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int cols=matrix[0].size();
        int l=0;
        int h=row*cols-1;

        while(l<=h){

            int mid=l+(h-l)/2;
            int row=mid/cols;
            int col=mid%cols;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return false;
    }
};
