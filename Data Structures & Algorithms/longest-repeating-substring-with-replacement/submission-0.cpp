class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp; // Character frequency
        int l = 0;
        int maxFreq = 0;             // Window me kisi bhi character ki maximum frequency
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {

            // Naya character window me add karo
            mp[s[r]]++;

            // Maximum frequency update karo
            maxFreq = max(maxFreq, mp[s[r]]);

            // Window size
            // r-l+1

            // Kitne characters replace karne padenge?
            // = Window Size - Most Frequent Character
            while ((r - l + 1) - maxFreq > k) {

                // Window invalid hai, left se shrink karo
                mp[s[l]]--;
                l++;
            }

            // Window valid hai
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};