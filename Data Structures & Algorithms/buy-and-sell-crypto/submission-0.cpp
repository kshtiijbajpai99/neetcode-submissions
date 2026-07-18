class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int ans=0;
        int n=prices.size();
        for(int r=1;r<n;r++){
            if(prices[r]>prices[l]){
                ans=max(ans,prices[r]-prices[l]);

            }
            else{
                l=r;
            }
        }
        return ans;
    }
};
