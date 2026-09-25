class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int ans =0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;

        
        while(mp[s[i]]>1){
            mp[s[l]]--;
            l++;
        }
        ans=max(ans,i-l+1);
        }
        return ans;
    }
};
