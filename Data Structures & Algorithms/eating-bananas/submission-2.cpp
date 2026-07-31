class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;

        while(l<=r){
            int totalh=0;
            int mid=l+(r-l)/2;
            for(int i=0;i<piles.size();i++){
                totalh+=ceil((double)piles[i]/mid);
            }
            if(totalh>h){
                l=mid+1;
            }
            else{

                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};
