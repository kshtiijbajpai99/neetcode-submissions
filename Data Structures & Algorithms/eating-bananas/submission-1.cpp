class Solution {
public:

bool caneat(vector<int>& piles, int h,int k){
    long long hours=0;
    for(int banana:piles){
        hours+=ceil((double)banana/k);
    }
    return hours<=h;
}


    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(caneat(piles,h,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }



        }
        return low;


        
    }
};
