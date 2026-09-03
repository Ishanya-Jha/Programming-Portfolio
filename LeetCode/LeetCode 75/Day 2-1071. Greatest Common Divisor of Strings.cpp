class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        // Check if both strings have the same repeating pattern
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Find the length of the answer
        int len = gcd(str1.size(), str2.size());

        // Take that many characters from the beginning
        return str1.substr(0, len);
    }
};
