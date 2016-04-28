class Solution {
public:
    int matchStar(char cMatchChar, string strStr, int nStrStart, string strPattern, int nPatternStart) {
        while (nStrStart < strStr.size() && (strStr[nStrStart] == cMatchChar || cMatchChar == '.')) {
            if (1 == matchStart(strStr, nStrStart, strPattern, nPatternStart)) {/* Match */
                return 1;
            }
            nStrStart++;
        }
        return matchStart(strStr, nStrStart, strPattern, nPatternStart);    
    }

    int matchStart(string strStr, int nStrStart, string strPattern, int nPatternStart) {
        if (nStrStart >= strStr.size() && nPatternStart >= strPattern.size()) {
            return 1;
        } 
        
       if (nPatternStart + 1 < strPattern.size() && strPattern[nPatternStart + 1] == '*') {
            nPatternStart = nPatternStart + 2;
            return matchStar(strPattern[nPatternStart - 2], strStr, nStrStart, strPattern, nPatternStart);
        } else if (nPatternStart < strPattern.size() && strPattern[nPatternStart] == '.') {
            if (nStrStart >= strStr.size()) {
                return -1;
            } 
            nStrStart++;
            nPatternStart++;
            return matchStart(strStr, nStrStart, strPattern, nPatternStart);
        } else if (nStrStart < strStr.size() && nPatternStart < strPattern.size() && strStr[nStrStart] == strPattern[nPatternStart]) {
            nStrStart++;
            nPatternStart++;
            return matchStart(strStr, nStrStart, strPattern, nPatternStart);
        }
        return -1;
    }

    bool isMatch(string s, string p) {
        int nStrStart = 0, nPatternStart = 0;
        if (matchStart(s, nStrStart, p, nPatternStart) == 1) {
            return true;
        }
        return false;
    }
};