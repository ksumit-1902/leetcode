class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        if(s1.length() > s2.length())
            return false;

        // Count frequency of s1 and first window of s2
        for(int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if(equal(freq1, freq1 + 26, freq2))
            return true;

        // Sliding window
        for(int i = s1.length(); i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - s1.length()] - 'a']--;

            if(equal(freq1, freq1 + 26, freq2))
                return true;
        }

        return false;
    }
};