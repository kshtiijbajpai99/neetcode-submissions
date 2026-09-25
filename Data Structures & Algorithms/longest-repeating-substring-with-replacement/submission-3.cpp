class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int ans =0;
        int maxifreq=0;
        unordered_map<char,int>mp;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;

            maxifreq=max(maxifreq,mp[s[r]]);
            if((r-l+1)-maxifreq>k){
                mp[s[l]]--;
                l++;
            
        }
        ans=max(ans,r-l+1);
        }
        return ans;


    }
};
