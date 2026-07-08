class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // Skip non-alphanumeric characters from the left
            while (i < j && !isalnum(s[i])) {
                i++;
            }

            // Skip non-alphanumeric characters from the right
            while (i < j && !isalnum(s[j])) {
                j--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};