class Solution {
public:
    string minWindow(string s, string t) {

        // Agar t bada hai to answer kabhi nahi milega
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> need;    // t me kitne characters chahiye
        unordered_map<char, int> window;  // Current window me kitne characters hai

        // t ki frequency store karo
        for (char ch : t)
            need[ch]++;

        int have = 0;               // Kitne unique characters ki requirement puri hui
        int required = need.size(); // Total unique characters required

        int l = 0;                  // Left pointer

        int start = 0;              // Answer kaha se start hoga
        int minLen = INT_MAX;       // Minimum window length

        // Right pointer se window expand karo
        for (int r = 0; r < s.size(); r++) {

            char ch = s[r];

            // Current character ko window me add karo
            window[ch]++;

            // Agar is character ki required frequency mil gayi
            if (need.count(ch) && window[ch] == need[ch])
                have++;

            // Agar saari requirements puri ho gayi
            while (have == required) {

                // Current window answer ho sakta hai
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Ab window ko chota karne ki koshish karo
                window[s[l]]--;

                // Agar important character kam ho gaya
                // to window invalid ho jayegi
                if (need.count(s[l]) && window[s[l]] < need[s[l]])
                    have--;

                // Left pointer aage badhao
                l++;
            }
        }

        // Agar answer mila hi nahi
        if (minLen == INT_MAX)
            return "";

        // Minimum window return karo
        return s.substr(start, minLen);
    }
};