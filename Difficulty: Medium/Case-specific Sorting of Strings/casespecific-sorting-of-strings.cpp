class Solution {
public:
    string caseSort(string& s) {
        int upper[26] = {0};
        int lower[26] = {0};

        // Count uppercase and lowercase letters
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                upper[ch - 'A']++;
            }
            else if (ch >= 'a' && ch <= 'z') {
                lower[ch - 'a']++;
            }
        }

        int u = 0, l = 0;

        // Rebuild string while preserving case positions
        for (int i = 0; i < s.size(); i++) {

            if (s[i] >= 'A' && s[i] <= 'Z') {

                while (u < 26 && upper[u] == 0) {
                    u++;
                }

                if (u < 26) {
                    s[i] = char(u + 'A');
                    upper[u]--;
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {

                while (l < 26 && lower[l] == 0) {
                    l++;
                }

                if (l < 26) {
                    s[i] = char(l + 'a');
                    lower[l]--;
                }
            }
        }

        return s;
    }
};